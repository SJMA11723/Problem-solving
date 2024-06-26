/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool detect_cycle(int node, int p, vector<int> graph[], bool vis[], int P[], int &cycle_start, int &cycle_end){
    //cout << "Intenta " << node + 1  << " desde " << p + 1 << '\n';
    if(vis[node]){
        cycle_start = node;
        cycle_end = p;
        //cout << "Start: " << cycle_start + 1 << '\n';
        return true;
    }
    vis[node] = true;
    P[node] = p;
    //cout << "Llega " << node + 1 << '\n';

    for(int v : graph[node]){
        if(v == p) continue;
        if(detect_cycle(v, node, graph, vis, P, cycle_start, cycle_end))
            return true;
    }
    return false;
}

struct pos{
    int node, d, p;
};

pair<int, int> bfs(int start, vector<int> graph[], bool in_cycle[], int n, bool marcel = false, int dest = -1){
    queue<pos> q;
    q.push({start, 0, -1});
    bool vis[n] = {};
    vis[start] = true;

    while(q.size()){
        pos act = q.front();
        q.pop();

        if(marcel && act.node == dest) return {act.d, act.d};
        if(!marcel && in_cycle[act.node]) return {act.node, act.d};

        for(int v : graph[act.node]){
            if(vis[v]) continue;
            vis[v] = true;
            q.push({v, act.d + 1, act.node});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        a--, b--;
        vector<int> graph[n];
        for(int i = 0; i < n; ++i){
            int from, to; cin >> from >> to;
            from--, to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int cycle_start = -1, cycle_end = -1;
        bool vis[n] = {}, in_cycle[n] = {};
        int P[n];
        detect_cycle(0, -1, graph, vis, P, cycle_start, cycle_end);
        for(int u = cycle_end; u != cycle_start; u = P[u]) in_cycle[u] = true;
        in_cycle[cycle_start] = true;

        auto [entry_point, val_dist] = bfs(b, graph, in_cycle, n);

        auto [mar_dist, foo] = bfs(a, graph, in_cycle, n, 1, entry_point);

        cout << (val_dist < mar_dist ? "YES\n" : "NO\n");
    }
}
