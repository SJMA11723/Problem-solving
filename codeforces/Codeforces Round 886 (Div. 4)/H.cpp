/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to;
    int64_t w;
};

bool assign_camp(int node, vector<edge> graph[], bool vis[], int64_t camps[], int64_t camp = 0){
    vis[node] = true;
    camps[node] = camp;

    for(edge &e : graph[node]){
        if(vis[e.to]){
            if(camps[e.to] != camp + e.w) return false;
            continue;
        }
        if(!assign_camp(e.to, graph, vis, camps, camp + e.w)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<edge> graph[n];
        int indeg[n] = {};
        for(int i = 0; i < m; ++i){
            int a, b, d; cin >> a >> b >> d;
            a--, b--;
            graph[a].push_back({b, d});
            graph[b].push_back({a, -d});
        }

        int64_t camps[n];
        bool ok = true, vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            ok = ok && assign_camp(i, graph, vis, camps);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
