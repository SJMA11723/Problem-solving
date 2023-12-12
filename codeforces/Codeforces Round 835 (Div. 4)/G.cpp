/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

struct edge{
    int to, w;
};

int a, b;
vector<bool> vis(MAXN);
set<int> vals;

void dfs_b(int node, int val_path, vector<edge> graph[]){
    vis[node] = true;

    for(edge &e : graph[node]){
        if(vis[e.to]) continue;
        int n_val = val_path ^ e.w;
        vals.insert(n_val);
        dfs_b(e.to, n_val, graph);
    }
}

void dfs_a(int node, int val_path, vector<edge> graph[]){
    vis[node] = true;

    if(vals.count(val_path))
        vis[b] = true;

    for(edge &e : graph[node]){
        if(vis[e.to]) continue;
        int n_val = val_path ^ e.w;
        if(e.to == b && n_val) continue;
        dfs_a(e.to, n_val, graph);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n >> a >> b;
        vector<edge> graph[n + 1];
        for(int i = 1; i < n; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vals.clear();
        fill(vis.begin(), vis.end(), false);
        dfs_b(b, 0, graph);

        fill(vis.begin(), vis.end(), false);
        dfs_a(a, 0, graph);
        if(vis[b]) cout << "YES\n";
        else cout << "NO\n";
    }
}
