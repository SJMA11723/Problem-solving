/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to;
    int w;
};

int P[100001];

bool check(const int n, vector<edge> DAG[], const long double MAX_AV){
    long double dist[n + 1];
    fill(dist, dist + n + 1, INT_MAX);
    memset(P, 0, sizeof(P));

    dist[1] = 0;
    for(int u = 1; u <= n; ++u){
        for(edge &e : DAG[u]){
            if(dist[e.to] > dist[u] + e.w - MAX_AV){
                dist[e.to] = dist[u] + e.w - MAX_AV;
                P[e.to] = u;
            }
        }
    }

    return dist[n] <= 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    long double l = 0, r = 101;
    for(int i = 0; i < 100; ++i){
        long double mid = l + (r - l) / 2;
        if(check(n, graph, mid)) r = mid;
        else l = mid;
    }

    check(n, graph, r);
    vector<int> ans;
    int act = n;
    while(act){
        ans.push_back(act);
        act = P[act];
    }

    cout << ans.size() - 1 << '\n';
    for(int i = ans.size() - 1; 0 <= i; --i) cout << ans[i] << " \n"[!i];
}
