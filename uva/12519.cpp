/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

bool bellman_ford(int s, int t, int n, vector<edge> &edges){
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    for(int i = 0; i < 2 * n; ++i){
        for(edge &e : edges){
            if(d[e.from] == INT_MAX) continue;
            if(d[e.from] + e.w < d[e.to]){
                d[e.to] = d[e.from] + e.w;
            }
        }
    }

    return d[t] < 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    while(n || m){
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            edges.push_back({a, b, c});
            edges.push_back({b, a, -c});
        }

        cout << (bellman_ford(0, 0, n, edges) ? 'Y' : 'N') << '\n';
        cin >> n >> m;
    }
}
