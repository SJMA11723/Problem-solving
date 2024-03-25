/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

struct edge{
    int from, to;
    int64_t w;
};

vector<edge> graph[MAXN], inv_graph[MAXN];
int scc[MAXN];
bool vis[MAXN];

void dfs(int node, vector<int> &topo_ord){
    if(vis[node]) return;
    vis[node] = true;
    for(edge &e : graph[node]) dfs(e.to, topo_ord);
    topo_ord.push_back(node);
}

void assign_scc(int node, const int id){
    if(vis[node]) return;
    vis[node] = true;
    scc[node] = id;
    for(edge &e : inv_graph[node]) assign_scc(e.to, id);
}

int kosajaru(int n){
    memset(vis, 0, sizeof(vis));
    vector<int> topo_ord;
    for(int i = 1; i <= n; ++i) dfs(i, topo_ord);
    reverse(topo_ord.begin(), topo_ord.end());
    memset(vis, 0, sizeof(vis));
    int id = 0;
    for(int u : topo_ord) if(!vis[u]) assign_scc(u, id++);
    return id;
}

int64_t dp[MAXN], cnt_scc[MAXN];
vector<edge> scc_graph[MAXN];

void build_scc_graph(int node){
    if(vis[node]) return;
    vis[node] = true;

    for(edge &e : graph[node]){
        if(scc[e.to] != scc[node]){
            scc_graph[ scc[node] ].push_back({scc[node], scc[e.to], e.w});
        } else {
            int64_t l = 0, r = e.w;
            while(l < r){
                int64_t mid = (l + r) / 2;
                if(mid * (mid + 1) / 2 > e.w) r = mid;
                else l = mid + 1;
            }
            r--;
            cnt_scc[scc[node]] += e.w * (r + 1) - r * (r + 1) * (r + 2) / 6;
        }
        build_scc_graph(e.to);
    }
}

int64_t compute(int scc_node){
    if(vis[scc_node]) return dp[scc_node];
    vis[scc_node] = true;

    int64_t res = 0;
    for(edge &e : scc_graph[scc_node]){
        res = max(res, e.w + compute(e.to));
    }

    return dp[scc_node] = cnt_scc[scc_node] + res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({a, b, w});
        inv_graph[b].push_back({b, a, w});
    }

    int cnt_comp = kosajaru(n);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) build_scc_graph(i);

    int s; cin >> s;
    memset(vis, 0, sizeof(vis));
    cout << compute(scc[s]) << '\n';
}
