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

void dfs(int u, vpii tree[], pii best[], pii second_best[], int cnt[], int p = -1){
    if(sz(tree[u]) == 1){
        best[u] = {0, u};
        second_best[u] = {INT_MAX, -1};
    } else best[u] = second_best[u] = {INT_MAX, -1};

    for(auto [v, l] : tree[u]){
        if(v == p) continue;
        dfs(v, tree, best, second_best, cnt, u);
        pii p = best[v]; p.fi += l;
        if(p < best[u]){
            second_best[u] = best[u];
            best[u] = p;
        } else if(p < second_best[u]) second_best[u] = p;
    }

    cnt[best[u].se]++;
}

void dfs_reroot(int u, vpii tree[], pii best[], pii second_best[], int cnt[], int ans[], vpii queries[], int p = -1){
    for(auto [s, idx] : queries[u]) ans[idx] = cnt[s];

    for(auto [v, l] : tree[u]){
        if(v == p) continue;

        pii prv_bestu = best[u];
        pii prv_bestv = best[v];
        pii prv_secbestv = second_best[v];
        cnt[best[u].se]--;
        cnt[best[v].se]--;

        if(best[u].se == best[v].se){
            // se regresa
            best[u] = second_best[u];
        }
        
        // agregamos a v la rama con u
        best[u].fi += l;
        if(best[u] < best[v]){
            // gana y avanza
            second_best[v] = best[v];
            best[v] = best[u];
        } else if(best[u] < second_best[v]) second_best[v] = best[u];
        best[u].fi -= l;
        cnt[best[u].se]++;
        cnt[best[v].se]++;

        dfs_reroot(v, tree, best, second_best, cnt, ans, queries, u);
        
        cnt[best[u].se]--;
        cnt[best[v].se]--;
        best[u] = prv_bestu;
        best[v] = prv_bestv;
        second_best[v] = prv_secbestv;
        cnt[best[u].se]++;
        cnt[best[v].se]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vpii tree[n];
    for(int i = 1; i < n; ++i){
        int u, v, l; cin >> u >> v >> l;
        u--, v--;
        tree[u].pb({v, l});
        tree[v].pb({u, l});
    }

    int q; cin >> q;
    vpii queries[n];
    int ans[q] = {};
    for(int i = 0; i < q; ++i){
        int s, t; cin >> s >> t;
        s--, t--;
        queries[t].pb({s, i});
    }

    pii best[n], second_best[n];
    int cnt[n] = {};
    dfs(0, tree, best, second_best, cnt);
    dfs_reroot(0, tree, best, second_best, cnt, ans, queries);

    for(int x : ans) cout << x << '\n';
}