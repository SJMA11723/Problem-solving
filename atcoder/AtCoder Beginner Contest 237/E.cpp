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

struct pos{
    int from;
    int64_t c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

int64_t dijkstra(int a, int n, vector<edge> graph[], int64_t p[]){
    int64_t dist[n];
    bool vis[n];
    fill(dist, dist + n, LLONG_MAX);
    memset(vis, 0, sizeof(vis));

    priority_queue<pos> q;
    q.push(pos{a, 0});
    dist[a] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(vis[act.from]) continue;
        vis[act.from] = true;

        for(edge &e : graph[act.from]){
            if(dist[e.to] < dist[act.from] + e.w + p[act.from] - p[e.to]) continue;

            dist[e.to] = dist[act.from] + e.w + p[act.from] - p[e.to];
            q.push(pos{e.to, dist[e.to]});
        }
    }

    int64_t mini = LLONG_MAX;
    for(int i = 0; i < n; ++i) mini = min(mini, dist[i] - p[0] + p[i]);

    return mini;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    int64_t h[n];
    for(int i = 0; i < n; ++i) cin >> h[i];

    vector<edge> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back({b, h[a] >= h[b] ? -(h[a] - h[b]) : 2 * (h[b] - h[a])});
        graph[b].push_back({a, h[b] >= h[a] ? -(h[b] - h[a]) : 2 * (h[a] - h[b])});
    }

    cout << -dijkstra(0, n, graph, h) << '\n';
}
