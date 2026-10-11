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

void topo_sort(int u, vi graph[], vi &topo_ord, bool vis[]){
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : graph[u]) topo_sort(v, graph, topo_ord, vis);
    topo_ord.pb(u);
}

void update_all(vi &topo_ord, vi graph[], int T[], int b[]){
    for(int u : topo_ord){
        T[u] = b[u];
        for(int v : graph[u]){
            T[u] += T[v];
            if(T[u] >= MOD) T[u] -= MOD;
        }
    }
}

vpii pending;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int b[n];
    for(int &x : b) cin >> x;
    
    int m; cin >> m;
    vi graph[n];
    for(int i = 0; i < m; ++i){
        int f, g; cin >> f >> g;
        f--, g--;
        graph[f].pb(g);
    }
    bool vis[n] = {};
    vi topo_ord;
    for(int i = 0; i < n; ++i) topo_sort(i, graph, topo_ord, vis);

    int dp[n][n]; memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) dp[i][i] = 1;
    for(int u : topo_ord){
        for(int v : topo_ord){
            if(u == v) break;
            for(int k : graph[u]){
                dp[u][v] += dp[k][v];
                if(dp[u][v] >= MOD) dp[u][v] -= MOD;
            }
        }
    }

    int T[n] = {};
    for(int u : topo_ord){
        T[u] = b[u];
        for(int v : graph[u]){
            T[u] += T[v];
            if(T[u] >= MOD) T[u] -= MOD;
        }
    }

    int e; cin >> e;
    pending.reserve(e);
    int ans = 0;
    int k = sqrt(m);
    int cnt_query = 1;
    int last_b[n];
    for(int i = 0; i < e; ++i){
        char c; cin >> c;
        if(c == 'U'){
            int I, V; cin >> I >> V;
            I--;
            pending.pb({I, V});
        } else {
            int J; cin >> J;
            J--;
            int last_T = T[J];
            if(sz(pending) >= k){
                for(auto [I, V] : pending) b[I] = V;
                pending.clear();
                update_all(topo_ord, graph, T, b);
                last_T = T[J];
            } else {
                for(auto [I, V] : pending) last_b[I] = b[I];
                last_T = T[J];
                for(auto [I, V] : pending){
                    T[J] += 1ll * (V - b[I] + MOD) * dp[J][I] % MOD;
                    if(T[J] >= MOD) T[J] -= MOD;
                    b[I] = V;
                }
                for(auto [I, V] : pending) b[I] = last_b[I];
            }
            ans += 1ll * cnt_query * T[J] % MOD;
            T[J] = last_T;
            if(ans >= MOD) ans -= MOD;
            cnt_query++;
        }
    }

    cout << ans << '\n';
}