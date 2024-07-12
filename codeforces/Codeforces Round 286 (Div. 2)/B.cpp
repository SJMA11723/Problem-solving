/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int color;
};

void dfs(int u, vector<edge> graph[], bool vis[], const int &color, const int &component, vector<vector<int>> &comp){
    if(vis[u]) return;
    vis[u] = true;
    comp[color][u] = component;
    for(edge &e : graph[u])
        if(e.color == color) dfs(e.to, graph, vis, color, component, comp);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
    }

    vector<vector<int>> comp(m + 1, vector<int>(n + 1));
    for(int c = 1; c <= m; ++c){
        int next_comp = 0;
        bool vis[n + 1] = {};
        for(int i = 1; i <= n; ++i){
            if(vis[i]) continue;
            dfs(i, graph, vis, c, next_comp, comp);
            next_comp++;
        }
    }

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        int ans = 0;
        for(int i = 1; i <= m; ++i) ans += comp[i][u] == comp[i][v];
        cout << ans << '\n';
    }
}
