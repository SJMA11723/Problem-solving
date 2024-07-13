/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<int> graph[], bool vis[]){
    if(vis[u]) return 0;
    vis[u] = true;
    int res = 1;
    for(int v : graph[u]) res += dfs(v, graph, vis);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s; cin >> n >> m >> s;
    vector<int> graph[n + 1];

    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    bool vis[n + 1] = {};
    dfs(s, graph, vis);

    vector<pair<int, int>> reach_sort;
    bool vis2[n + 1] = {};
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        memset(vis2, 0, sizeof(vis2));
        reach_sort.push_back({dfs(i, graph, vis2), i});
    }

    sort(reach_sort.begin(), reach_sort.end(), greater<pair<int, int>>());

    int ans = 0;
    for(auto [r, i] : reach_sort){
        if(vis[i]) continue;
        ans++;
        dfs(i, graph, vis);
    }

    cout << ans << '\n';
}
