/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

vector<int> any_cycle(int n, vector<edge> &edges){
    vector<int64_t> d(n, 0);
    vector<int> P(n, -1);
    int last_relax = -1;
    for(int i = 0; i < n; ++i){
        last_relax = -1;
        for(edge &e : edges){
            if(d[e.from] + e.w < d[e.to]){
                last_relax = e.from;
                d[e.to] = d[e.from] + e.w;
                P[e.to] = e.from;
            }
        }
    }

    if(last_relax == -1) return {};

    int cur = last_relax;
    for(int i = 0; i < n; ++i) cur = P[cur];
    vector<int> cycle;
    bool vis[n] = {};
    for(int i = 0; i < n; ++i){
        if(vis[cur]) break;
        vis[cur] = true;
        cycle.push_back(cur);
        cur = P[cur];
    }
    reverse(cycle.begin(), cycle.end());

    return cycle;
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
        edges.push_back({a, b, c});
    }

    vector<int> ans = any_cycle(n, edges);

    if(ans.empty()) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << ' ';
        cout << ans[0] + 1 << '\n';
    }
}
