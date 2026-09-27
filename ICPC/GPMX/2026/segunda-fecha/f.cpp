/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define fi first
#define se second

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

/*
// =============== DEBUG ============
const bool deb = 0;
#define DEBUG if(deb)

template<typename A, typename B> ostream & operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
// ==================================
*/

#define is_on(S, i) ((S) & (1 << (i)))

array<int, 4> C[4][20];
int key_odd_down[4][20];
int key_even_down[4][20];

//vector<vvll> dp[2];
//const int MAX_SUBSETS = 184756;
//array<array<ll, 20>, 4> dp[2][MAX_SUBSETS];

struct comp_down{
    bool operator()(pair<int, pii> A, pair<int, pii> B){
        //return key_even_down[A.se][A.fi] < key_odd_down[B.se][B.fi];
        return key_even_down[A.se.se][A.se.fi] < B.fi;
    }
};

/*bool comp_down(pii A, pii B){
    return key_even_down[A.se][A.fi] < key_odd_down[B.se][B.fi];
}*/

struct comp_up{
    bool operator()(pair<int, pii> A, pair<int, pii> B){
        //return -key_even_down[A.se][A.fi] < -key_odd_down[B.se][B.fi];
        return -key_even_down[A.se.se][A.se.fi] < -B.fi;
    }
};

struct comp_sort{
    bool operator()(pair<int, pii> &A, pair<int, pii> &B){
        return A.first < B.first;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    int MAX_SUBSETS = 1;
    for(int i = 0; i < n / 2; ++i){
        MAX_SUBSETS *= n - i;
        MAX_SUBSETS /= i + 1;
    }
    array<array<ll, 20>, 4> dp[2][MAX_SUBSETS];

    int l0[n], r0[n], l1[n], r1[n];
    int width[4][n];
    ll cost_down[4][n], cost_up[4][n];
    ll cost_nxtdown[4][n], cost_nxtup[4][n];
    for(int i = 0; i < n; ++i){
        cin >> l0[i] >> r0[i] >> l1[i] >> r1[i];
        C[0][i] = {l0[i], r0[i], l1[i], r1[i]};
        C[1][i] = {r0[i], l0[i], r1[i], l1[i]}; // H
        C[2][i] = {l1[i], r1[i], l0[i], r0[i]}; // V
        C[3][i] = {r1[i], l1[i], r0[i], l0[i]}; // HV
        for(int k = 0; k < 4; ++k){
            width[k][i] = max(C[k][i][0], C[k][i][2]) + max(C[k][i][1], C[k][i][3]);
            key_even_down[k][i] = C[k][i][0] - C[k][i][2];
            key_odd_down[k][i] = C[k][i][3] - C[k][i][1];
            cost_down[k][i] = C[k][i][1] + max(C[k][i][0], C[k][i][2]) - width[k][i];
            cost_up[k][i] = C[k][i][3] + max(C[k][i][0], C[k][i][2]) - width[k][i];
            cost_nxtdown[k][i] = C[k][i][0] + max(C[k][i][1], C[k][i][3]);
            cost_nxtup[k][i] = C[k][i][2] + max(C[k][i][1], C[k][i][3]);
        }
    }
    // costo unir abajo si C[k1][i][3] - C[k1][i][1] <= C[k2][j][0] - C[k2][j][2]
    // cost[k1][k2][i][j] = (C[k1][i][1] + max(C[k1][i][0], C[k1][i][2])) + (C[k2][j][0] + max(C[k2][j][1], C[k2][j][3]));

    // costo unir arriba si C[k1][i][1] - C[k1][i][3] <= C[k2][j][2] - C[k2][j][0]
    // cost[k1][k2][i][j] = (C[k1][i][3] + max(C[k1][i][0], C[k1][i][2])) + (C[k2][j][2] + max(C[k2][j][1], C[k2][j][3])) );

    int lim = 1 << n;
    vi cub[n + 1];
    int idx[lim];
    for(int mask = 1; mask < lim; ++mask){
        idx[mask] = sz(cub[__builtin_popcount(mask)]);
        cub[__builtin_popcount(mask)].pb(mask);
    }

    // inicializa dp
    //dp[0].resize(MAX_SUBSETS, vvll(4, vll(n, LLONG_MAX)));
    //dp[1].resize(MAX_SUBSETS, vvll(4, vll(n, LLONG_MAX)));
    for(int k = 0; k < 4; ++k) for(int i = 0; i < n; ++i){
        dp[1][idx[1 << i]][k][i] = width[k][i];
    }

    //long double tiempo_fase1 = 0;
    //long double tiempo_fase2 = 0;

    //vpii trans_up; // para cuando se unen arriba
    vll pref_minup;
    //vpii trans_down; // para cuando se unen abajo
    vector<pair<int, pii>> trans_down, cur_trans;
    vll pref_mindown;
    trans_down.reserve(4 * n);
    cur_trans.reserve(4 * n);
    pref_minup.reserve(4 * n);
    pref_mindown.reserve(4 * n);

    for(int i = 0; i < n; ++i) for(int k = 0; k < 4; ++k)
        trans_down.pb({key_odd_down[k][i], {i, k}});
    sort(all(trans_down), comp_sort());

    for(int bits = 1; bits < n; ++bits)
    for(int mask : cub[bits]){
        // precalculando transiciones
        //auto t0 = chrono::high_resolution_clock::now();
        for(pair<int, pii> &p : trans_down) if(is_on(mask, p.se.fi)) cur_trans.pb(p);
        
        int idx_mask = idx[mask];
        int i = cur_trans[0].se.fi;
        int k = cur_trans[0].se.se;
        pref_mindown.pb(dp[bits & 1][idx_mask][k][i] + cost_down[k][i]);
        for(int j = 1; j < sz(cur_trans); ++j){
            i = cur_trans[j].se.fi;
            k = cur_trans[j].se.se;
            pref_mindown.pb(min(pref_mindown.back(), dp[bits & 1][idx_mask][k][i] + cost_down[k][i]));
        }

        i = cur_trans.back().se.fi;
        k = cur_trans.back().se.se;
        pref_minup.pb(dp[bits & 1][idx_mask][k][i] + cost_up[k][i]);
        for(int j = sz(cur_trans) - 2; 0 <= j; --j){
            i = cur_trans[j].se.fi;
            k = cur_trans[j].se.se;
            pref_minup.pb(min(pref_minup.back(), dp[bits & 1][idx_mask][k][i] + cost_up[k][i]));
        }
        //auto t1 = chrono::high_resolution_clock::now();
        //tiempo_fase1 += chrono::duration<double, milli>(t1 - t0).count();

        // inicia la dp hacia adelante
        int comp_mask = (lim - 1) ^ mask;
        //t0 = chrono::high_resolution_clock::now();
        while(comp_mask){
            // elijo el siguiente para agregar
            int j = __builtin_ctz(comp_mask);

            int new_mask = mask | (1 << j);
            int idx_new_mask = idx[new_mask];

            // Elijo la orientacion del siguiente
            for(int k2 = 0; k2 < 4; ++k2){
                // encuentro el primero valido para unir arriba
                int nlayer = (bits & 1) ^ 1;
                dp[nlayer][idx_new_mask][k2][j] = LLONG_MAX;

                //int pos = upper_bound(all(trans_down), pair<int, pii>{key_even_down[k2][j], {j, k2}}, comp_down()) - trans_down.begin();
                int key_nxt = key_even_down[k2][j];

                int l = 0, r = sz(cur_trans);
                while(l < r){
                    int mid = (l + r) / 2;
                    if(key_nxt < cur_trans[mid].fi) r = mid;
                    else l = mid + 1;
                }
                int pos = l;
                if(pos > 0){
                    pos--;
                    dp[nlayer][idx_new_mask][k2][j] = pref_mindown[pos] + cost_nxtdown[k2][j];
                }

                //pos = upper_bound(trans_down.rbegin(), trans_down.rend(), pair<int, pii>{key_even_down[k2][j], {j, k2}}, comp_up()) - trans_down.rbegin();
                /*l = 0, r = sz(trans_down);
                while(l < r){
                    int mid = (l + r) / 2;
                    if(key_nxt <= trans_down[mid].fi) r = mid;
                    else l = mid + 1;
                }*/
                while(r > 0 && key_nxt <= cur_trans[r - 1].fi) r--;
                pos = sz(cur_trans) - r;
                if(pos > 0){
                    pos--;
                    dp[nlayer][idx_new_mask][k2][j] = min(dp[nlayer][idx_new_mask][k2][j], 1ll * pref_minup[pos] + cost_nxtup[k2][j]);
                }
            }
            comp_mask &= comp_mask - 1;
        }
        //t1 = chrono::high_resolution_clock::now();
        //tiempo_fase2 += chrono::duration<double, milli>(t1 - t0).count();
        cur_trans.clear();
        pref_minup.clear();
        pref_mindown.clear();
    }

    ll ans = LLONG_MAX;
    for(int k = 0; k < 4; ++k) for(int i = 0; i < n; ++i)
        ans = min(ans, dp[n & 1][idx[lim - 1]][k][i]);
    cout << ans << '\n';

    //cout << "Tiempo fase 1 = " << fixed << setprecision(4) << tiempo_fase1 / 1000 << '\n';
    //cout << "Tiempo fase 2 = " << fixed << setprecision(4) << tiempo_fase2 / 1000 << '\n';
}
