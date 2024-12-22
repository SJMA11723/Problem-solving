#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int w;
};

vector<int64_t> bellman_ford(int s, int n, vector<edge> &edges){
    vector<int64_t> d(n, LLONG_MAX);
    d[s] = 0;
    for(int i = 1; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == LLONG_MAX) continue;
            if(d[e.to] <= d[e.from] + e.w) continue;
            d[e.to] = d[e.from] + e.w;
        }
    }

    vector<int> graph[n];
    for(edge &e : edges) graph[e.from].push_back(e.to);

    bool vis[n] = {};
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] <= d[e.from] + e.w) continue;
        d[e.to] = d[e.from] + e.w;

        queue<int> q;
        q.push(e.to);
        vis[e.to] = true;
        d[e.to] = LLONG_MIN;
        while(q.size()){
            int u = q.front();
            q.pop();

            for(int v : graph[u]){
                if(vis[v]) continue;
                vis[v] = true;
                d[v] = LLONG_MIN;
                q.push(v);
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<edge> edges(m);
    for(edge &e : edges){
        cin >> e.from >> e.to >> e.w;
        e.from--;
        e.to--;
    }

    int p[n];
    for(int &x : p) cin >> x;

    for(edge &e : edges) e.w -= p[e.to];

    vector<int64_t> d = bellman_ford(s, n, edges);

    if(d[t] == LLONG_MIN) cout << "Money hack!\n";
    else if(d[t] == LLONG_MAX) cout << "Bad trip\n";
    else cout << -d[t] << '\n';
}
