/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

vector<vector<int64_t>> floyd_warshall(int n, vector<edge> &edges){
    vector<vector<int64_t>> d(n, vector<int64_t>(n, LLONG_MAX));
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(edge &e : edges)
        if(d[e.from][e.to] > e.w) d[e.from][e.to] = d[e.to][e.from] = e.w;

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == LLONG_MAX) continue;
                if(d[k][j] == LLONG_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    vector<vector<int64_t>> d = floyd_warshall(n, edges);

    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        if(d[a][b] == LLONG_MAX) cout << "-1\n";
        else cout << d[a][b] << '\n';
    }
}
