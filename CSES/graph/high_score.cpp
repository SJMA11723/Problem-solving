/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w;
};

int64_t bellman_ford(int s, int t, int n, vector<edge> &edges){
    vector<int64_t> d(n, LLONG_MAX);
    d[s] = 0;
    for(int i = 1; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == LLONG_MAX) continue;
            d[e.to] = min(d[e.to], d[e.from] + e.w);
        }
    }

    vector<int> graph[n];
    for(edge &e : edges) graph[e.from].push_back(e.to);

    vector<bool> vis(n);
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] <= d[e.from] + e.w) continue;
        d[e.to] = d[e.from] + e.w;
        queue<int> q;
        q.push(e.from);
        vis[e.from] = true;
        d[e.from] = LLONG_MIN;
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v : graph[u])
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
                d[v] = LLONG_MIN;
            }
        }
    }

    return d[t];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, -c});
    }

    int64_t ans = bellman_ford(0, n - 1, n, edges);

    if(ans == LLONG_MIN) ans = 1;
    cout << -ans << '\n';
}
