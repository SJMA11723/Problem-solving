#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int p[n];
    for(int &x : p) cin >> x;

    vector<pii> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    ll dist[n];
    fill(dist, dist + n, LLONG_MAX);
    bool vis[n] = {};
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 0});
    dist[0] = 0;

    ll ans = 0;

    while(q.size()){
        int u = q.top().se; q.pop();

        if(vis[u]) continue;
        vis[u] = 1;
        ans += dist[u] * p[u];

        for(pii &e : graph[u]){
            int v, w;
            tie(v, w) = e;

            if(dist[v] <= dist[u] + w) continue;

            dist[v] = dist[u] + w;
            q.push({dist[v], v});
        }
    }

    cout << ans << '\n';
}