#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w;
    const bool operator<(const edge &b)const{
        return w > b.w;
    }
};

struct pos{
    int p, from;
    int64_t c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

void dijkstra(int a, int n, vector<edge> graph[], int64_t dist[], vector<int> min_graph[]){
    bool vis[n] = {};
    fill(dist, dist + n, LLONG_MAX);
    priority_queue<pos> pq;
    pq.push({-1, a, 0});
    dist[a] = 0;
    while(pq.size()){
        pos act = pq.top();
        pq.pop();

        if(dist[act.from] == act.c && act.p != -1) min_graph[act.p].push_back(act.from);
        if(vis[act.from]) continue;
        vis[act.from] = true;

        for(edge &e : graph[act.from]){
            if(dist[e.to] < dist[act.from] + e.w) continue;

            dist[e.to] = dist[act.from] + e.w;
            pq.push({act.from, e.to, dist[e.to]});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int p, g; cin >> p >> g;
    p--, g--;
    vector<edge> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
    }

    int64_t dist[n];
    vector<int> min_graph[n];
    dijkstra(p, n, graph, dist, min_graph);

    queue<int> q;
    q.push(p);
    bool vis[n] = {};
    vis[p] = true;
    while(q.size()){
        int u = q.front(); q.pop();
        if(u == g) continue;
        for(int v : min_graph[u]){
            if(vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; ++i)
        if(!vis[i] && dist[i] == 2 * dist[g]) ans.push_back(i + 1);

    if(ans.size()) for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    else cout << "*\n";
}
