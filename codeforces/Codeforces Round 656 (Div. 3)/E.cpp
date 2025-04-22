/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    bool is_undirected;
};

bool detect_cycle(int u, vector<int> graph[], char vis[]){
    if(vis[u] == 2) return false;
    vis[u] = 1;

    bool res = false;
    for(int v : graph[u]){
        if(vis[v] == 1) return true;
        res |= detect_cycle(v, graph, vis);
    }
    vis[u] = 2;
    return res;
}

void dfs(int u, vector<int> graph[], char vis[], vector<int> &topo_ord){
    if(vis[u]) return;
    vis[u] = true;
    for(int v : graph[u]) dfs(v, graph, vis, topo_ord);
    topo_ord.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> graph[n];
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int d, a, b;
            cin >> d >> a >> b;
            a--, b--;
            if(d) graph[a].push_back(b);
            edges.push_back({a, b, !d});
        }

        bool cycle = false;
        char vis[n] = {};
        for(int i = 0; i < n; ++i)
        if(!vis[i]) cycle |= detect_cycle(i, graph, vis);

        if(cycle){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        memset(vis, 0, sizeof(vis));
        vector<int> topo_ord;
        for(int i = 0; i < n; ++i) dfs(i, graph, vis, topo_ord);
        reverse(topo_ord.begin(), topo_ord.end());

        int topo_pos[n];
        for(int i = 0; i < n; ++i) topo_pos[ topo_ord[i] ] = i;

        for(edge &e : edges){
            if(e.is_undirected && topo_pos[e.from] > topo_pos[e.to]) cout << e.to + 1 << ' ' << e.from + 1 << '\n';
            else cout << e.from + 1 << ' ' << e.to + 1 << '\n';
        }
    }
}
