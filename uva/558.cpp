/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

bool bellman_ford(int s, int n, vector<edge> &edges){
    const int INF = INT_MAX;
    vector<int> d(n);
    bool relax = false;
    for(int i = 0; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == INF) continue;
            if(d[e.to] <= d[e.from] + e.w) continue;
            if(i + 1 == n) relax = true;
            d[e.to] = d[e.from] + e.w;
        }
    }
    return relax;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            edges.push_back({a, b, c});
        }
        cout << (bellman_ford(0, n, edges) ? "possible\n" : "not possible\n");
    }
}
