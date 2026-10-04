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
#define lsb(S) ((S) & -(S))

struct worker{
    int H = -1, L, U;
    bool operator<(const worker &b){
        return H < b.H;
    }
};

struct fenwick_tree{
    int n;
    vll BIT, prodBIT;
    
    fenwick_tree(int _n){
        n = _n;
        BIT.resize(n + 1);
        prodBIT.resize(n + 1);
    }

    void add(int pos, int x, int h){
        while(pos <= n){
            BIT[pos] += x;
            prodBIT[pos] += 1ll * x * h;
            pos += lsb(pos);
        }
    }

    ll sum(int pos){
        ll res = 0;
        while(pos){
            res += BIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }

    ll prodsum(int pos){
        ll res = 0;
        while(pos){
            res += prodBIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, S, K; cin >> N >> S >> K;
    vector<worker> arr(N + 1);
    for(int i = 1; i <= N; ++i){
        worker &w = arr[i];
        cin >> w.H >> w.L >> w.U;
    }
    sort(all(arr));
    
    vi events; events.reserve(2 * N);
    for(int i = 1; i <= N; ++i){
        events.pb(i);
        events.pb(-i);
    }
    sort(all(events), [&](int &i, int &j){
        int Ai = i > 0 ? arr[i].L : arr[-i].U;
        int Bi = arr[abs(i)].H;
        int Aj = j > 0 ? arr[j].L : arr[-j].U;
        int Bj = arr[abs(j)].H;
        if(Ai * Bj == Aj * Bi) return i > j;
        return Ai * Bj < Aj * Bi;
    });

    fenwick_tree BIT(N);
    ll ans_num = LLONG_MAX, ans_den = 1;
    for(int idx : events){
        if(idx > 0){
            BIT.add(idx, K / arr[idx].H, arr[idx].H);
            int l = 0, r = N + 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(BIT.sum(mid) < S) l = mid + 1;
                else r = mid;
            }
            if(r == N + 1) continue;

            ll cur_num = arr[idx].L;
            ll cur_den = arr[idx].H;
            ll g = __gcd(cur_num, cur_den);
            cur_num /= g;
            cur_den /= g;
            ll hours = BIT.prodsum(r - 1) + (S - BIT.sum(r - 1)) * arr[r].H;
            g = __gcd(hours, cur_den);
            hours /= g;
            cur_den /= g;
            cur_num *= hours;

            if(ans_num == LLONG_MAX || ans_num * cur_den > cur_num * ans_den){
                ans_num = cur_num;
                ans_den = cur_den;
            }
        } else {
            idx = -idx;
            BIT.add(idx, -K / arr[idx].H, arr[idx].H);
        }
    }

    if(ans_num == LLONG_MAX) cout << "*\n";
    else cout << ans_num << ' ' << ans_den << '\n';
}