/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
#define is_on(S, i) ((S) & (1 << (i)))

struct edge{
    int from, to, w;
};

const int INF = 1e9;

vvi floyd_warshall(int n, vector<edge> &edges){
    vvi d(n, vi(n, INF));
    for(edge &e : edges) d[e.from][e.to] = d[e.to][e.from] = min(d[e.from][e.to], e.w);
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, m; cin >> n >> m;

        vector<edge> edges;
        int deg[n] = {}, ans = 0;
        for(int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            edges.push_back({a, b, c});
            deg[a]++;
            deg[b]++;
            ans += c;
        }

        vi odd_deg;
        for(int i = 0; i < n; ++i) if(deg[i] & 1) odd_deg.pb(i);

        vvi d = floyd_warshall(n, edges);

        int N = sz(odd_deg);
        int lim = 1 << N;
        int dp[lim];
        memset(dp, 0, sizeof(dp));
        for(int mask = 1; mask < lim; ++mask){
            dp[mask] = INF;
            if(__builtin_popcount(mask) == 1) continue;
            int u = __builtin_ctz(mask);
            int prv_mask = mask ^ (1 << u);
            for(int v = 0; v < N; ++v)
                if(is_on(prv_mask, v)) dp[mask] = min(dp[mask], dp[prv_mask ^ (1 << v)] + d[odd_deg[u]][odd_deg[v]]);
        }
        ans += dp[lim - 1];
        cout << "Case " << tt << ": " << ans << '\n';
    }
}