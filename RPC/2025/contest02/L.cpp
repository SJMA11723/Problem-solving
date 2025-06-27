#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to, d, v, w;
};

struct pos{
    int from;
    long double c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

long double dijkstra(int n, vector<edge> graph[], const int t){
    long double dist[n];
    bool vis[n] = {};
    fill(dist,  dist + n, LLONG_MAX);
    priority_queue<pos> q;
    q.push({0, 0});
    dist[0] = 0;
    while(q.size()){
        pos cur = q.top();
        q.pop();

        if(vis[cur.from]) continue;
        vis[cur.from] = true;

        for(edge &e : graph[cur.from]){
            long double w;
            if(cur.c >= t) w = (long double) e.d / e.w;
            else if(cur.c + (long double)e.d / e.v < t) w = (long double) e.d / e.v;
            else w = t - cur.c + (long double) (e.d - (t - cur.c) * e.v) / e.w;

            if(dist[e.to] <= cur.c + w) continue;
            dist[e.to] = cur.c + w;
            q.push({e.to, dist[e.to]});
        }
    }

    return dist[n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t; cin >> n >> m >> t;
    vector<edge> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b, d, v, w;
        cin >> a >> b >> d >> v >> w;
        a--, b--;
        graph[a].push_back({b, d, v, w});
        graph[b].push_back({a, d, v, w});
    }

    cout << fixed << setprecision(9) << dijkstra(n, graph, t) << '\n';
}
