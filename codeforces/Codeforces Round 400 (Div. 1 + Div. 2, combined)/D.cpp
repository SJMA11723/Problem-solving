/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct two_sat{
    int n;
    vector<vector<int>> graph, inv_graph;
    vector<int> scc;
    vector<bool> vis;
    two_sat(){}

    two_sat(int _n){
        n = _n;
        graph.resize(2 * n);
        inv_graph.resize(2 * n);
        scc.resize(2 * n);
        vis.resize(2 * n);
    }

    void add_edge(int u, int v){
        graph[u].push_back(v);
        inv_graph[v].push_back(u);
    }

    void add_or(int p, bool val_p, int q, bool val_q){
        add_edge(p + (val_p ? n : 0), q + (val_q ? 0 : n));
        add_edge(q + (val_q ? n : 0), p + (val_p ? 0 : n));
    }

    void add_xor(int p, bool val_p, int q, bool val_q){
        add_or(p, val_p, q, val_q);
        add_or(p, !val_p, q, !val_q);
    }

    void add_and(int p, bool val_p, int q, bool val_q){
        add_xor(p, !val_p, q, val_q);
    }

    void dfs(int node, vector<int> &topo_ord){
        if(vis[node]) return;
        vis[node] = true;
        for(int v : graph[node]) dfs(v, topo_ord);
        topo_ord.push_back(node);
    }

    void assign_scc(int node, const int id){
        if(vis[node]) return;
        vis[node] = true;
        scc[node] = id;
        for(int v : inv_graph[node]) assign_scc(v, id);
    }

    bool build_ans(){
        fill(vis.begin(), vis.end(), false);
        vector<int> topo_ord;

        for(int i = 0; i < 2 * n; ++i) dfs(i, topo_ord);
        fill(vis.begin(), vis.end(), false);
        reverse(topo_ord.begin(), topo_ord.end());

        int id = 0;
        for(int u : topo_ord) if(!vis[u]) assign_scc(u, id++);

        for(int i = 0; i < n; ++i)
            if(scc[i] == scc[i + n]) return false;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    bool open[n];
    for(int i = 0; i < n; ++i) cin >> open[i];

    vector<int> controls[n];
    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        while(x--){
            int idx; cin >> idx;
            idx--;
            controls[idx].push_back(i);
        }
    }

    two_sat sat(m);

    for(int i = 0; i < n; ++i){
        int p = controls[i][0],
            q = controls[i][1];
        if(open[i])
            sat.add_and(p, 1, q, 1);
        else
            sat.add_xor(p, 1, q, 1);
    }

    cout << (sat.build_ans() ? "YES\n" : "NO\n");
}
