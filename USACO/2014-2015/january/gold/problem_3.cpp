/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'001

using namespace std;

vector<int> graph[MAXN], inv_graph[MAXN];
int scc[MAXN];
bool vis[MAXN];

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

int kosajaru(int n){
    memset(vis, 0, sizeof(vis));
    vector<int> topo_ord;
    for(int i = 0; i < n; ++i) dfs(i, topo_ord);

    memset(vis, 0, sizeof(vis));
    reverse(topo_ord.begin(), topo_ord.end());
    int id = 0;
    for(int u : topo_ord) if(!vis[u]) assign_scc(u, id++);
    return id;
}

vector<int> scc_graph[MAXN], inv_scc_graph[MAXN];
int cnt_scc[MAXN];

void build_scc_graph(int n, int n_scc){
    for(int u = 0; u < n; ++u)
        for(int v : graph[u])
            if(scc[u] != scc[v])
                scc_graph[scc[u]].push_back(scc[v]);

    for(int u = 0; u < n_scc; ++u){
        sort(scc_graph[u].begin(), scc_graph[u].end());
        auto it = unique(scc_graph[u].begin(), scc_graph[u].end());
        scc_graph[u].resize(it - scc_graph[u].begin());

        for(int v : scc_graph[u])
            inv_scc_graph[v].push_back(u);
    }
}

int dp[2][MAXN];

int compute(int node, bool inv){
    if(dp[inv][node]) return dp[inv][node];
    if(node == scc[0]) return 0;

    int res = INT_MIN;
    if(inv){
        for(int v : inv_scc_graph[node])
            res = max(res, compute(v, inv));
    } else {
        for(int v : scc_graph[node])
            res = max(res, compute(v, inv));
    }
    res += cnt_scc[node];
    return dp[inv][node] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("grass.in");
    ofstream cout("grass.out");

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        inv_graph[b].push_back(a);
    }

    int size_scc = kosajaru(n);
    memset(vis, 0, sizeof(vis));
    build_scc_graph(n, size_scc);
    for(int i = 0; i < n; ++i) cnt_scc[scc[i]]++;

    for(int i = 0; i < size_scc; ++i){
        compute(i, 0);
        compute(i, 1);
    }

    int ans = cnt_scc[scc[0]];
    for(int u = 0; u < size_scc; ++u){
        if(dp[0][u] < 0) continue;
        for(int v : scc_graph[u]){
            if(dp[1][v] < 0) continue;
            ans = max(ans, dp[0][u] + dp[1][v] + cnt_scc[scc[0]]);
        }
    }

    cout << ans << '\n';
}
