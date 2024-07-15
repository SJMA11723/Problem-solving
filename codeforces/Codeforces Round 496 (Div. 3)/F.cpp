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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<edge> graph[n];
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        edges.push_back({a, b, i});
        graph[a].push_back({a, b, i});
        graph[b].push_back({b, a, i});
    }

    int dist[n];
    fill(dist, dist + n, INT_MAX);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int cur = q.front();
        q.pop();

        for(edge & e : graph[cur]){
            if(dist[e.to] != INT_MAX) continue;
            dist[e.to] = dist[cur] + 1;
            q.push(e.to);
        }
    }

    vector<int> shortest_path_graph[n];
    for(edge &e : edges){
        if(dist[e.from] + 1 == dist[e.to]) shortest_path_graph[e.to].push_back(e.idx);
        else if(dist[e.to] + 1 == dist[e.from]) shortest_path_graph[e.from].push_back(e.idx);
    }

    int idx[n] = {};
    vector<string> ans;
    while(k--){
        string used(m, '0');

        for(int i = 1; i < n; ++i)
            used[shortest_path_graph[i][ idx[i] ]] = '1';
        ans.push_back(used);

        bool new_tree = false;
        for(int i = 1; i < n; ++i){
            if(idx[i] + 1 < shortest_path_graph[i].size()){
                idx[i]++;
                new_tree = true;
                break;
            } else idx[i] = 0;
        }
        if(!new_tree) break;
    }

    cout << ans.size() << '\n';
    for(string s : ans) cout << s << '\n';
}
