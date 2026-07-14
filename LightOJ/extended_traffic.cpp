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

vll bellman_ford(int s, int n, vector<edge> &edges, bool cycles = 0){
    vll d(n, cycles ? 0 : LLONG_MAX);
    d[s] = 0;
    for(int i = 1; i < n; ++i)
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
        }
    }

    bool vis[n] = {};
    for(int i = 0; i < n; ++i)
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
            vis[e.to] = 1;
        }
    }
    for(int i = 0; i < n; ++i) if(vis[i] || d[i] == LLONG_MAX)
        d[i] = -1;

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;
        int m; cin >> m;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            ll diff = arr[b] - arr[a];
            edges.pb({a, b, diff * diff * diff});
        }
        vll ans = bellman_ford(0, n, edges);
        int q; cin >> q;
        cout << "Case " << tt << ":\n";
        while(q--){
            int x; cin >> x; x--;
            if(ans[x] < 3) cout << "?\n";
            else cout << ans[x] << '\n';
        }
    }
}