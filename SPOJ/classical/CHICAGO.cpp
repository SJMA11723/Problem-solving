/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    long double w;
};

vector<vector<long double>> floyd_warshall(int n, vector<edge> &edges){
    vector<vector<long double>> d(n, vector<long double>(n, INT_MAX));
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(edge &e : edges)
        if(d[e.from][e.to] > e.w) d[e.from][e.to] = d[e.to][e.from] = e.w;

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == INT_MAX) continue;
                if(d[k][j] == INT_MAX) continue;
                d[i][j] = min(d[i][j], -abs(d[i][k] * d[k][j]));
            }
        }
    }

    return d;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        int n; cin >> n;
        if(!n) break;
        int m; cin >> m;
        vector<edge> edges(m);
        for(edge &e : edges){
            cin >> e.from >> e.to >> e.w;
            e.from--;
            e.to--;
            e.w = -e.w / 100;
        }

        vector<vector<long double>> d = floyd_warshall(n, edges);

        cout << fixed << setprecision(6) << -d[0][n - 1] * 100 << " percent\n";
    }
}
