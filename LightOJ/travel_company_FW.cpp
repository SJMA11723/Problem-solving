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

bool floyd_warshall(int n, vector<edge> &edges){
    const int INF = INT_MAX;
    vvi d(n, vi(n, INF));
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(edge &e : edges)
        d[e.from][e.to] = e.w;

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i = 0; i < n; ++i) if(d[i][i] < 0) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, r, p; cin >> n >> r >> p;
        vector<edge> edges;
        for(int i = 0; i < r; ++i){
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            edges.push_back({u, v, -(a - b * p)});
        }
        cout << "Case " << tt << ": " << (floyd_warshall(n, edges) ? "YES\n" : "NO\n");
    }
}

