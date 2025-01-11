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

bool bellman_ford(int s, int t, int n, vector<edge> &edges, const int64_t MIN){
    vector<int64_t> d(n, LLONG_MAX);
    d[s] = 0;
    for(int i = 1; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == LLONG_MAX) continue;
            if(e.w < MIN) continue;
            if(d[e.from] + e.w < d[e.to]){
                d[e.to] = d[e.from] + e.w;
            }
        }
    }

    return d[t] != LLONG_MAX;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int cnt = 1;
    while(n || m){
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int a, b;
            int64_t c; cin >> a >> b >> c;
            a--, b--;
            edges.push_back({a, b, c});
            edges.push_back({b, a, c});
        }
        int s, t;
        int64_t p;
        cin >> s >> t >> p;
        s--, t--;

        int64_t l = 0, r = LLONG_MAX;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            if(bellman_ford(s, t, n, edges, mid)) l =  mid + 1;
            else r = mid;
            //cout << l << ' ' << r << '\n';
        }
        l--;

        cout << "Scenario #" << cnt++ << '\n';
        cout << "Minimum Number of Trips = " << (p + l - 2) / (l - 1) << "\n\n";

        cin >> n >> m;
    }
}
