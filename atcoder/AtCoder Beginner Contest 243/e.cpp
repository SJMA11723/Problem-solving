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
    ll w;
};

vvll floyd_warshall(int n, vector<edge> &edges){
    const ll INF = LLONG_MAX;
    vvll d(n, vll(n, INF));
    for(edge &e : edges) d[e.from][e.to] = d[e.to][e.from] = e.w;
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            if(d[i][k] == INF) continue;
            for(int j = 0; j < n; ++j){
                if(d[k][j] == INF) continue;
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.pb({a, b, c});
    }
    vvll d = floyd_warshall(n, edges);
    int ans = 0;
    for(edge &e : edges){
        bool ok = 0;
        for(int k = 0; k < n; ++k){
            if(k == e.from || k == e.to || max(d[e.from][k], d[k][e.to]) == LLONG_MAX)
                continue;
            if(d[e.from][k] + d[k][e.to] <= e.w){
                ok = 1;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}
