/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int w;
};

vector<int> bellman_ford(int s, int n, vector<edge> &edges, bool cycles = false){
    vector<int> d(n, (cycles ? 0 : INT_MAX));
    d[s] = 0;
    vector<int> P(n, -1);

    for(int i = 0; i < n - 1; ++i){
        for(edge &e : edges){
            if(d[e.from] == INT_MAX) continue;

            if(d[e.to] > d[e.from] + e.w){
                d[e.to] = d[e.from] + e.w;
                P[e.to] = e.from;
            }
        }
    }

    int last_relax = -1;
    for(edge &e : edges){
        if(d[e.from] == INT_MAX) continue;

        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
            P[e.to] = e.from;
            last_relax = e.to;
        }
    }

    if(last_relax == -1) return d;
    return {}; /// VACIO
}

struct pos{
    int from;
    long long c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

vector<int> dijkstra(int a, int n, vector<edge> graph[], const vector<int> &p){
    vector<int> dist(n);
    bool visitado[n];
    fill(dist.begin(), dist.end(), INT_MAX);
    memset(visitado, 0, sizeof(visitado));

    priority_queue<pos> q;
    q.push(pos{a, 0});
    dist[a] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(visitado[act.from]) continue;
        visitado[act.from] = true;

        for(edge &e : graph[act.from]){
            if(dist[e.to] < dist[act.from] + e.w + p[e.from] - p[e.to]) continue;

            dist[e.to] = dist[act.from] + e.w + p[e.from] - p[e.to];
            q.push(pos{e.to, dist[e.to]});
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        int m; cin >> m;
        vector<edge> edges;

        vector<edge> graph[n];
        for(int i = 0; i < m; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            edges.push_back({a, b, w});
            graph[a].push_back({a, b, w});
        }

        vector<int> p = bellman_ford(0, n, edges, true);
        if(p.empty()){
            cout << "graph " << tt << " no\n\n";
            continue;
        }

        cout << "graph " << tt << " yes\n\n";
        for(int i = 0; i < n; ++i)
            cout << p[i] << ' ';
        cout << "0\n\n";

        for(int i = 0; i < n; ++i){
            vector<int> d = dijkstra(i, n, graph, p);
            for(int j = 0; j < n; ++j){
                if(d[j] == INT_MAX) cout << "# ";
                else cout << d[j] - p[i] + p[j] << ' ';
            }
            cout << '\n';
        } cout << '\n';
    }
}
