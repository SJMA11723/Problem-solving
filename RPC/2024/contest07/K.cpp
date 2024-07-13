/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void bfs(int s, int n, vector<int> graph[], int64_t dist[]){
    fill(dist, dist + n, INT_MAX);

    if(s == n) return;

    bool vis[n] = {};

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = true;

    while(q.size()){
        int cur = q.front();
        q.pop();

        for(int v : graph[cur]){
            if(vis[v]) continue;
            vis[v] = true;
            dist[v] = dist[cur] + 1;
            q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w; cin >> h >> w;
    int block[h][w], n_pieces = 0;
    set<int> top;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> block[i][j];
            n_pieces = max(n_pieces, block[i][j]);
            if(!i) top.insert(block[i][j]);
        }
    }

    set<pair<int, int>> edges;
    vector<int> graph[n_pieces + 1], inv_graph[n_pieces + 1];

    for(int i = 1; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(block[i][j] == block[i - 1][j] || edges.count({block[i - 1][j], block[i][j]})) continue;

            graph[block[i - 1][j]].push_back(block[i][j]); /// hacia abajo
            inv_graph[block[i][j]].push_back(block[i - 1][j]); /// hacia arriba
            edges.insert({block[i - 1][j], block[i][j]});
        }
    }

    for(int j = 0; j < w; ++j){
        int mini = min(0, block[h - 1][j]);
        int maxi = max(0, block[h - 1][j]);
        if(0 == block[h - 1][j] || edges.count({0, block[h - 1][j]})) continue;

        graph[block[h - 1][j]].push_back(0); /// hacia abajo
        inv_graph[0].push_back(block[h - 1][j]); /// hacia arriba
        edges.insert({block[h - 1][j], 0});
    }

    int64_t dist_a[n_pieces + 1], dist_b[n_pieces + 1], dist_0[n_pieces + 1];
    bfs(*top.begin(), n_pieces + 1, graph, dist_a);

    fill(dist_b, dist_b + n_pieces + 1, INT_MAX);
    if(top.size() == 2) bfs(*top.rbegin(), n_pieces + 1, graph, dist_b);

    bfs(0, n_pieces + 1, inv_graph, dist_0);

    int64_t ans = LLONG_MAX;
    for(int i = 0; i <= n_pieces; ++i){
        if(top.size() == 1) ans = min(ans, dist_0[i] + dist_a[i]);
        else {
            int64_t ndist = dist_0[i] + dist_a[i] + dist_b[i];
            ans = min(ans, ndist);
        }
    }

    cout << ans << '\n';
}
