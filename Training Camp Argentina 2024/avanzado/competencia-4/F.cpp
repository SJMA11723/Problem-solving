/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int idx;
};

void dfs(int u, vector<edge> graph[], bool vis[], bool used[], int64_t &ans, int &cnt_nodes){
    if(vis[u]) return;
    vis[u] = true;
    cnt_nodes++;

    for(edge &e : graph[u]){
        if(!used[e.idx]){
            used[e.idx] = true;
            ans--;
        }
        dfs(e.to, graph, vis, used, ans, cnt_nodes);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int c[k];
    for(int &x : c) cin >> x;

    vector<edge> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        graph[u].push_back({u, v, i});
        graph[v].push_back({v, u, i});
    }

    int64_t ans = 0;
    int max_comp = 0;
    bool used[m] = {}, vis[n + 1] = {};
    for(int i = 0; i < k; ++i){
        int cnt_nodes = 0;
        dfs(c[i], graph, vis, used, ans, cnt_nodes);
        ans += cnt_nodes * (cnt_nodes - 1) / 2;
        max_comp = max(max_comp, cnt_nodes);
    }

    for(int i = 1; i <= n; ++i) if(!vis[i]) ans += max_comp++;
    for(int i = 0; i < m; ++i) if(!used[i]) ans--;

    cout << ans << '\n';
}
