/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, idx;
};

int detect_bridges(int u, vector<edge> graph[], bool vis[], bool is_bridge[], int t_in[], int t = 1, int p = -1){
    if(vis[u]) return t_in[u];

    vis[u] = true;
    t_in[u] = t;

    int min_back_edge = INT_MAX;
    for(edge &e : graph[u]){
        if(e.idx == p || (vis[e.to] && t_in[e.to] > t_in[u])) continue;

        int min_child_back_edge = detect_bridges(e.to, graph, vis, is_bridge, t_in, t + 1, e.idx);
        if(min_child_back_edge > t_in[u]) is_bridge[e.idx] = true;

        min_back_edge = min(min_back_edge, min_child_back_edge);
    }

    return min_back_edge;
}

struct dsu{
    vector<int> RA, P;
    int cnt;

    dsu(int n){
        cnt = n;
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[x] >= RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        cnt--;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> graph[n];
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back({a, b, i});
        graph[b].push_back({b, a, i});
        edges.push_back({a, b, i});
    }

    bool is_bridge[m] = {};
    bool vis[n] = {};
    int t_in[n] = {};
    for(int i = 0; i < n; ++i){
        detect_bridges(i, graph, vis, is_bridge, t_in);
    }

    dsu mset(n);
    int comp_deg[n] = {};
    for(edge &e : edges)
        if(!is_bridge[e.idx]) mset.join(e.from, e.to);

    for(edge &e : edges)
        if(is_bridge[e.idx]) comp_deg[mset.root(e.from)]++, comp_deg[e.to]++;

    if(mset.cnt == 1){
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i){
        if(vis[mset.root(i)]) continue;
        vis[mset.root(i)] = true;
        ans += max(0, 2 - comp_deg[mset.root(i)]);
    }
    ans = (ans + 1) / 2;

    cout << ans << '\n';
}
