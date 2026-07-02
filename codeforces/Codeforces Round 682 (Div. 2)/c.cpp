/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

struct two_sat{
    int n;
    vvi graph, inv_graph;
    vi scc, ans;
    vector<bool> vis;
    two_sat(){}
    two_sat(int _n){
        n = _n;
        graph.resize(2 * n);
        inv_graph.resize(2 * n);
        scc.resize(2 * n);
        vis.resize(2 * n);
        ans.resize(n);
    }

    void add_edge(int u, int v){
        graph[u].pb(v);
        inv_graph[v].pb(u);
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

    void dfs(int u, vi &topo_ord){
        if(vis[u]) return;
        vis[u] = 1;
        for(int v : graph[u]) dfs(v, topo_ord);
        topo_ord.pb(u);
    }

    void assign_scc(int u, const int id){
        if(vis[u]) return;
        vis[u] = 1;
        scc[u] = id;
        for(int v : inv_graph[u]) assign_scc(v, id);
    }

    bool build_ans(){
        fill(all(vis), false);
        vi topo_ord;
        for(int i = 0; i < 2 * n; ++i) dfs(i, topo_ord);
        fill(all(vis), false);
        reverse(all(topo_ord));
        int id = 0;
        for(int u : topo_ord) if(!vis[u]) assign_scc(u, id++);
        for(int i = 0; i < n; ++i){
            if(scc[i] == scc[i + n]) return 0;
            ans[i] = (scc[i] < scc[i + n] ? 0 : 1);
        }
        return 1;
    }
};

int n, m;

int id(int i, int j){
    return i * m + j;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        int mat[n][m];
        two_sat sat(n * m);
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            if(i){
                if(mat[i][j] == mat[i - 1][j]) sat.add_xor(id(i, j), 1, id(i - 1, j), 1);
                else if(abs(mat[i][j] - mat[i - 1][j]) == 1) sat.add_and(id(i, j), 1, id(i - 1, j), 1);
            }
            if(j){
                if(mat[i][j] == mat[i][j - 1]) sat.add_xor(id(i, j), 1, id(i, j - 1), 1);
                else if(abs(mat[i][j] - mat[i][j - 1]) == 1) sat.add_and(id(i, j), 1, id(i, j - 1), 1);
            }
        }

        sat.build_ans();
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cout << mat[i][j] + sat.ans[id(i, j)] << " \n"[j + 1 == m];
    }
}
