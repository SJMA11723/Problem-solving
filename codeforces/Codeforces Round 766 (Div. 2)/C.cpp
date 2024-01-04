/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to, i;
};

void dfs(int node, bool two, bool vis[], int ans[], vector<edge> graph[]){
    vis[node] = true;
    for(edge &e : graph[node]){
        if(vis[e.to]) continue;
        ans[e.i] = two ? 2 : 5;
        dfs(e.to, !two, vis, ans, graph);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<edge> graph[n + 1];
        int deg[n + 1] = {};
        bool ok = true;
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            graph[a].push_back({b, i});
            graph[b].push_back({a, i});
            deg[a]++;
            deg[b]++;
            if(deg[a] > 2 || deg[b] > 2) ok = false;
        }
        if(!ok){
            cout << "-1\n";
            continue;
        }

        int ans[n];
        bool vis[n + 1] = {};
        dfs(find(deg, deg + n + 1, 1) - deg, true, vis, ans, graph);
        for(int i = 1; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
