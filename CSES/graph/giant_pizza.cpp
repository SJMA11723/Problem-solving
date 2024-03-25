/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct two_sat{
    int n;
    vector<vector<int>> graph, inv_graph;
    vector<int> scc, topo_ord, ans;
    vector<bool> vis;

    two_sat(int _n){
        n = _n;
        graph.resize(2 * n);
        inv_graph.resize(2 * n);
        scc.resize(2 * n);
        vis.resize(2 * n);
        ans.resize(n);
    }

    void add_edge(int u, int v){
        graph[u].push_back(v);
        inv_graph[v].push_back(u);
    }

    void add_or(int p, bool val_p, int q, bool val_q){
        add_edge(p + (val_p ? n : 0), q + (val_q ? 0 : n));
        add_edge(q + (val_q ? n : 0), p + (val_p ? 0 : n));
    }

    void dfs(int node, vector<int> &order){
        if(vis[node]) return;
        vis[node] = true;
        for(int v : graph[node]) dfs(v, order);
        order.push_back(node);
    }

    void assign_scc(int node, const int root){
        if(vis[node]) return;
        vis[node] = true;
        scc[node] = root;
        for(int v : inv_graph[node]) assign_scc(v, root);
    }

    bool build_ans(){
        fill(vis.begin(), vis.end(), false);

        for(int i = 0; i < 2 * n; ++i) dfs(i, topo_ord);
        fill(vis.begin(), vis.end(), false);
        reverse(topo_ord.begin(), topo_ord.end());

        int id = 0;
        for(int u : topo_ord) if(!vis[u]) assign_scc(u, id++);

        for(int i = 0; i < n; ++i){
            if(scc[i] == scc[i + n]) return false;
            ans[i] = (scc[i] < scc[i + n] ? 0 : 1);
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    two_sat sat(m);
    for(int i = 0; i < n; ++i){
        int a, b;
        char val_a, val_b;
        cin >> val_a >> a >> val_b >> b;
        a--; b--;
        sat.add_or(a, val_a == '+', b, val_b == '+');
    }

    bool ok = sat.build_ans();
    if(!ok) cout << "IMPOSSIBLE\n";
    else {
        for(int i = 0; i < m; ++i) cout << (sat.ans[i] ? '+' : '-') << ' ';
        cout << '\n';
    }
}
