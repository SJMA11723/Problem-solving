/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'001

using namespace std;

struct edge{
    int to;
    int w;
};

struct pos{
    int from;
    int c, d;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

vector<int> path;

bool dijkstra(int a, int b, vector<edge> graph[], const int MAX_W, const int d, bool save = false){
    int dist[MAXN], prev[MAXN] = {};
    bool vis[MAXN];
    fill(dist, dist + MAXN, INT_MAX);
    memset(vis, 0, sizeof(vis));

    priority_queue<pos> q;
    q.push(pos{a, 0, 0});
    dist[a] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(vis[act.from]) continue;
        vis[act.from] = true;

        for(edge &e : graph[act.from]){
            if(act.d >= d || max(dist[act.from], e.w) > MAX_W) continue;

            if(max(dist[act.from], e.w) < dist[e.to]){
                prev[e.to] = act.from;
                dist[e.to] = max(dist[act.from], e.w);
            }
            q.push(pos{e.to, dist[e.to], act.d + 1});
        }
    }

    if(save){
        int act = b;
        while(act){
            path.push_back(act);
            act = prev[act];
        }
    }

    return dist[b] != INT_MAX;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d; cin >> n >> m >> d;

    vector<edge> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    if(!dijkstra(1, n, graph, INT_MAX, d)){
        cout << "-1\n";
        return 0;
    }

    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(dijkstra(1, n, graph, mid, d)) r = mid;
        else l = mid + 1;
    }

    dijkstra(1, n, graph, l, d, true);
    cout << path.size() - 1 << '\n';
    for(int i = path.size() - 1; 0 <= i; --i) cout << path[i] << " \n"[!i];
}
