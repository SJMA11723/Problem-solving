/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, idx, x;
};

bool dfs(int u, vector<edge> graph[], bool vis[], bool color[], bool ans[]){
    vis[u] = true;
    bool res = true;
    for(edge &e : graph[u]){
        ans[e.idx] = color[u] ^ e.x;

        if(vis[e.to]){
            if(color[e.to] == color[u]) return false;
            continue;
        }

        color[e.to] = !color[u];
        res = dfs(e.to, graph, vis, color, ans) && res;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back({a, b, i, 0});
        graph[b].push_back({b, a, i, 1});
    }

    bool vis[n] = {};
    bool color[n] = {};
    bool ans[m] = {};
    if(dfs(0, graph, vis, color, ans)){
        cout << "YES\n";
        for(int i = 0; i < m; ++i) cout << ans[i];
        cout << '\n';
        return 0;
    }

    memset(vis, 0, sizeof(vis));
    color[0] = 1;
    if(dfs(0, graph, vis, color, ans)){
        cout << "YES\n";
        for(int i = 0; i < m; ++i) cout << ans[i];
        cout << '\n';
        return  0;
    }

    cout << "NO\n";
}
