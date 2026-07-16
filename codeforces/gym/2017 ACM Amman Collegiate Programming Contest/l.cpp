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

ll bellman_ford(int n, vector<edge> &edges){
    vll d(n, 0);
    for(int i = 1; i < n; ++i)
    for(edge &e : edges) d[e.to] = min(d[e.to], d[e.from] + e.w);
    for(edge &e : edges) if(d[e.to] > d[e.from] + e.w) return LLONG_MIN;
    return *min_element(all(d));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<edge> edges;
        int min_edge = INT_MAX;
        for(int i = 0; i < m; ++i){
            int u, v, c; cin >> u >> v >> c;
            u--, v--;
            edges.pb({u, v, c});
            min_edge = min(min_edge, c);
        }
        ll ans = bellman_ford(n, edges);
        if(ans == LLONG_MIN) cout << "-inf\n";
        else cout << (ans ? ans : min_edge) << '\n';
    }    
}
