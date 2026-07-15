/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vld> vvld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define EPS 1e-7

const int MOD = 1e9 + 7;

struct edge{
    int from, to;
    ld w;
};

vvld floyd_warshall(int n, vector<edge> &edges){
    const ld INF = 4000;
    vvld d(n, vld(n, INF));
    for(edge &e : edges) d[e.from][e.to] = d[e.to][e.from] = e.w;
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
    int n, m;
    while(cin >> n >> m){
        if(n == m && n == 0) break;
        int x[n], y[n];
        for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

        bool adj[n][n];
        memset(adj, 0, sizeof(adj));
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int u, v; cin >> u >> v;
            u--, v--;
            adj[u][v] = adj[v][u] = 1;
            edges.pb({u, v, sqrtl((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]))});
        }

        vvld d = floyd_warshall(n, edges);
        int u_ans = -1, v_ans = -1;
        ld max_sum = 0, dist_uv = 0;
        for(int u = 0; u < n; ++u)
        for(int v = u + 1; v < n; ++v){
            if(u == v || adj[u][v]) continue;
            ld dist = sqrtl((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
            ld cur_sum = 0;
            for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cur_sum += d[i][j] - min({d[i][j], d[i][u] + dist + d[v][j], d[i][v] + dist + d[u][j]});
            if(u_ans == -1 || cur_sum > max_sum + EPS){
                max_sum = cur_sum;
                u_ans = u;
                v_ans = v;
                dist_uv = dist;
            } else if(fabsl(cur_sum - max_sum) < EPS){
                if(dist + EPS < dist_uv){
                    u_ans = u;
                    v_ans = v;
                    dist_uv = dist;
                } else if(fabsl(dist - dist_uv) < EPS && pii(u, v) < pii(u_ans, v_ans)){
                    u_ans = u;
                    v_ans = v;
                }
            }
        }

        if(u_ans == -1 || max_sum < 1.0) cout << "No road required\n";
        else cout << u_ans + 1 << ' ' << v_ans + 1 << '\n';
    }
}
