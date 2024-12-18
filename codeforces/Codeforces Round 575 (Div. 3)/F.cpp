/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w;

    const bool operator<(const edge &b)const{
        return w < b.w;
    }
};

vector<vector<int64_t>> floyd_warshall(int n, vector<edge> graph[]){
    const int64_t INF = LLONG_MAX;
    vector<vector<int64_t>> d(n, vector<int64_t>(n, INF));
    /// aqui inicializa con la lista/matriz de adyacencia
    for(int i = 0; i < n; ++i){
        d[i][i] = 0;
        for(edge &e : graph[i]){
            d[i][e.to] = e.w;
            d[e.to][i] = e.w;
        }
    }

    /// luego calcula la dp
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == INF) continue;
                if(d[k][j] == INF) continue;

                if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end());

    int idx[n] = {}; fill(idx, idx + n, -1);
    int cur_idx = 0;
    for(int i = 0; i < min(m, k); ++i){
        int u = edges[i].from, v = edges[i].to;
        if(idx[u] == -1) idx[u] = cur_idx++;
        if(idx[v] == -1) idx[v] = cur_idx++;
    }

    n = cur_idx;
    vector<edge> graph[n];

    for(int i = 0; i < min(m, k); ++i){
        int u = edges[i].from, v = edges[i].to;
        u = idx[u];
        v = idx[v];
        int64_t w = edges[i].w;
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }

    vector<vector<int64_t>> d = floyd_warshall(n, graph);
    vector<int64_t> paths;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            paths.push_back(d[i][j]);
        }
    }

    sort(paths.begin(), paths.end());
    cout << paths[k - 1] << '\n';
}
