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

bool bellman_ford(int n, vector<edge> &edges, const long double MAX){
    vector<long double> d(n, INT_MAX);
    vector<int> P(n, -1);
    d[0] = 0;
    for(int i = 1; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == INT_MAX) continue;
            if(e.w > MAX) continue;
            if(d[e.from] + e.w < d[e.to]){
                d[e.to] = d[e.from] + e.w;
                P[e.to] = e.from;
            }
        }
    }

    long double res = 0;
    int cur = 1;
    while(P[cur] != -1){
        res = max(res, d[cur] - d[P[cur]]);
        cur = P[cur];
    }

    return res <= MAX && d[1] != INT_MAX;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt = 1;
    while(n){
        pair<int, int> points[n];
        vector<edge> edges;
        for(int i = 0; i < n; ++i){
            cin >> points[i].first >> points[i].second;
            for(int j = 0; j < i; ++j){
                int dx = (points[i].first - points[j].first);
                int dy = (points[i].second - points[j].second);
                long double d = sqrt(dx * dx + dy * dy);
                edges.push_back({i, j, d});
                edges.push_back({j, i, d});
            }
        }

        long double l = 0, r = 1e9;
        for(int i = 0; i < 50; ++i){
            long double mid = l + (r - l) / 2;
            if(bellman_ford(n, edges, mid)) r = mid;
            else l = mid;
        }

        cout << "Scenario #" << cnt++ << '\n';
        cout << "Frog Distance = " << fixed << setprecision(3) << l << "\n\n";

        cin >> n;
    }
}
