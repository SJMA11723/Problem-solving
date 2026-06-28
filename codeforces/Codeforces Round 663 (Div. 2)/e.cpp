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

void dfs(int u, vi graph[], vi tree[], bool vis[]){
    vis[u] = 1;
    for(int v : graph[u]){
        if(vis[v]) continue;
        tree[u].pb(v); tree[v].pb(u);
        dfs(v, graph, tree, vis);
    }
}

void diam(int u, vi tree[], int &max_node, int &maxd, int d = 1, int p = 0){
    if(maxd < d) tie(max_node, maxd) = {u, d};
    for(int v : tree[u]) if(v != p) diam(v, tree, max_node, maxd, d + 1, u);
}

int ceiln = 0;
void path(int u, vi tree[], vi &ans, int p = 0){
    ans.pb(u);
    for(int v : tree[u]) if(v != p && sz(ans) < ceiln) path(v, tree, ans, u);
    if(sz(ans) < ceiln) ans.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        ceiln = (n + 1) / 2;
        vi graph[n + 1];
        for(int i = 0; i < m; ++i){
            int u, v; cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vi tree[n + 1];
        bool vis[n + 1] = {};
        dfs(1, graph, tree, vis);
        int max_node = -1, maxd = 0;
        diam(1, tree, max_node, maxd);
        maxd = 0;
        diam(max_node, tree, max_node, maxd);

        if(maxd < ceiln){
            // emparejamiento
            vi cub[maxd + 1];
            queue<pii> q;
            q.push({1, 0});
            memset(vis, 0, sizeof(vis));
            vis[1] = 1;

            while(sz(q)){
                int u, d; tie(u, d) = q.front();
                q.pop();
                cub[d].pb(u);

                for(int v : tree[u]) if(!vis[v]){
                    vis[v] = 1;
                    q.push({v, d + 1});
                }
            }

            vpii ans;
            for(int i = 0; i < maxd; ++i)
            while(sz(cub[i]) > 1){
                int a = cub[i].back(); cub[i].pop_back();
                int b = cub[i].back(); cub[i].pop_back();
                ans.pb({a, b});
            }

            cout << "PAIRING\n" << sz(ans) << '\n';
            for(int i = 0; i < sz(ans); ++i) cout << ans[i].fi << ' ' << ans[i].se << '\n';
        } else {
            // camino
            vi ans;
            path(max_node, tree, ans);
            cout << "PATH\n" << sz(ans) << '\n';
            for(int i = 0; i < sz(ans); ++i) cout << ans[i] << " \n"[i + 1 == sz(ans)];
        }
    }
}