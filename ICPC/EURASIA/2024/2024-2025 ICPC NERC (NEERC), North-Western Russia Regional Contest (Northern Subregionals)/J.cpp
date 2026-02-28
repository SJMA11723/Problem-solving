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
#define sz(x) (int)(x).size()
#define pb push_back

const int MOD = 1e9 + 7;

void ciclos(int u, char vis[], vi graph[], vi G[]){
    vis[u] = 1;
    for(int v : graph[u]){
        if(vis[v] == 1) continue;
        G[u].pb(v);
        if(!vis[v]) ciclos(v, vis, graph, G);
    }
}

void topo_sort(int u, char vis[], vi graph[], vi &topo){
    vis[u] = 1;
    for(int v : graph[u]){
        if(vis[v]) continue;
        topo_sort(v, vis, graph, topo);
    }
    topo.pb(u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int in_deg[n] = {};
        int out_deg[n] = {};
        vi graph[n], inv_graph[n];
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            out_deg[a]++;
            in_deg[b]++;
            graph[a].pb(b);
            inv_graph[b].pb(a);
        }
 
        set<pii> mset;
        for(int i = 0; i < n; ++i){
            mset.insert({-out_deg[i] + in_deg[i], i});
        }
 
        int cnt = 0;
        bool vis[n] = {};
        vi ans;
        while(sz(mset)){
            int u = mset.begin()->second;
            vis[u] = true;
            ans.pb(u + 1);
            mset.erase(mset.begin());
 
            for(int v : graph[u]){
                if(vis[v]) continue;
 
                cnt++;
                mset.erase({-out_deg[v] + in_deg[v], v});
                in_deg[v]--;
                mset.insert({-out_deg[v] + in_deg[v], v});
            }
 
            for(int v : inv_graph[u]){
                if(vis[v]) continue;
                mset.erase({-out_deg[v] + in_deg[v], v});
                out_deg[v]--;
                mset.insert({-out_deg[v] + in_deg[v], v});
            }
        }
 
        if(cnt >= (m + 1) / 2) for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
        else cout << "-1\n";
    }
}