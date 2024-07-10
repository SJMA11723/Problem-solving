/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<int> graph[], bool vis[]){
    if(vis[u]) return true;
    vis[u] = true;
    bool res = graph[u].size() == 2;
    for(int v : graph[u]) res = dfs(v, graph, vis) && res; /// cuidado con el orden de dfs && res
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    bool vis[n] = {};
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        ans += dfs(i, graph, vis);
    }
    cout << ans << '\n';
}
