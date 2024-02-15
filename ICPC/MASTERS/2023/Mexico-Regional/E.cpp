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

vector<int64_t> bellman_ford(int s, int t, int n, vector<edge> &edges, bool cycles = false){
    vector<int64_t> d(n, (cycles ? 0 : LLONG_MAX));
    d[s] = 0;

    for(int i = 0; i < n - 1; ++i){
        for(edge &e : edges){
            if(d[e.from] == LLONG_MAX) continue;

            if(d[e.to] > d[e.from] + e.w){
                d[e.to] = d[e.from] + e.w;
            }
        }
    }

    bool target_relaxed = false;

    for(int i = 0; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == LLONG_MAX) continue;

            if(d[e.to] > d[e.from] + e.w){
                d[e.to] = d[e.from] + e.w;
                if(e.to == t) target_relaxed = true;
            }
        }
    }

    if(!target_relaxed) return d;
    return {}; /// VACIO
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        edges.push_back({a, b, w});
    }

    int64_t p[n];
    for(int i = 0; i < n; ++i) cin >> p[i];

    for(edge &e : edges) e.w -= p[e.to];

    vector<int64_t> d = bellman_ford(s, t, n, edges);

    if(d.empty()){
        cout << "Money hack!\n";
        return 0;
    }

    if(d[t] == LLONG_MAX){
        cout << "Bad trip\n";
        return 0;
    }

    cout << -d[t] << '\n';
}
