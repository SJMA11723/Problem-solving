/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

struct pos{
    int from, c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

void dijkstra(int u, int n, vector<edge> graph[], vector<vector<int>> &d){
    int dist[n] = {};
    bool vis[n] = {};
    fill(dist, dist + n, INT_MAX);
    priority_queue<pos> q;
    q.push(pos{u, 0});
    dist[u] = 0;
    while(q.size()){
        pos cur = q.top();
        q.pop();

        if(vis[cur.from]) continue;
        vis[cur.from] = true;
        d[u][cur.from] = cur.c;

        for(edge &e : graph[cur.from]){
            if(dist[e.to] <= dist[cur.from] + e.w) continue;
            dist[e.to] = dist[cur.from] + e.w;
            q.push(pos{e.to, dist[e.to]});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<edge> graph[n];
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
        edges.push_back({a, b, c});
    }

    pair<int, int> paths[k];
    for(int i = 0; i < k; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        paths[i] = {a, b};
    }

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; ++i) dijkstra(i, n, graph, dist);

    int ans = INT_MAX;
    for(int i = 0; i < m; ++i){
        edge &e = edges[i];
        int sum = 0;
        for(int j = 0; j < k; ++j){
            int l, r;
            tie(l, r) = paths[j];
            sum += min({dist[l][r], dist[l][e.from] + dist[e.to][r], dist[l][e.to] + dist[e.from][r]});
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}
