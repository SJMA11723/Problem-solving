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

struct edge{
    int from, to;
    int w;
};

const int INF = 1e9;
vvi floyd_warshall(int n, vector<edge> &edges){
    vvi d(n, vi(n, INF));
    for(edge &e : edges) d[e.from][e.to] = d[e.to][e.from] = min(d[e.to][e.from], e.w);
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
        int n, m, k; cin >> n >> m >> k;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int a, b, g; cin >> a >> b >> g;
            a--, b--;
            edges.pb({a, b, g});
        }

        vvi dist = floyd_warshall(n, edges);
        int s[k], d[k];
        bool ok  = 1;
        for(int i = 0; i < k; ++i){
            cin >> s[i] >> d[i];
            s[i]--, d[i]--;
            if(max(dist[0][s[i]], dist[0][d[i]]) == INF) ok = 0;
        }
        
        if(!ok){
            cout << "Case #" << tt << ": -1\n";
            continue;
        }

        if(k == 1){
            cout << "Case #" << tt << ": " << dist[0][s[0]] + dist[s[0]][d[0]] << '\n';
            continue;
        }

        // d[0][i]: ans pending i located at s_i
        // d[1][i]: ans pending i located at d_{i - 1}
        int dp[2][k];
        for(int i = 0; i < k; ++i) dp[0][i] = dp[1][i] = INF;
        dp[0][0] = dist[0][s[0]];
        dp[0][1] = dist[0][s[0]] + dist[s[0]][d[0]] + dist[d[0]][s[1]];
        dp[1][1] = dist[0][s[0]] + dist[s[0]][s[1]] + dist[s[1]][d[0]];
        for(int i = 2; i < k; ++i){
            dp[0][i] = min(dp[0][i - 1] + dist[s[i - 1]][d[i - 1]],
                           dp[1][i - 1] + dist[d[i - 2]][d[i - 1]]) + dist[d[i - 1]][s[i]];
            dp[1][i] = min(dp[0][i - 1] + dist[s[i - 1]][s[i]],
                           dp[1][i - 1] + dist[d[i - 2]][s[i]]) + dist[s[i]][d[i - 1]];
        }
        cout << "Case #" << tt << ": " << min(dp[0][k - 1] + dist[s[k - 1]][d[k - 1]], dp[1][k - 1] + dist[d[k - 2]][d[k - 1]]) << '\n';
    }
}
