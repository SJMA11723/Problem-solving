#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

int deg[MAXN + 1];

struct edge{
    int from, to;
    int idx;
    int64_t paths;

    bool operator<(const edge &b)const{
        if(paths == b.paths) return deg[from] < deg[b.from];
        return paths < b.paths;
    }
};

void dfs(int u, vector<edge> tree[], vector<int> &subtree, int p = -1){
    subtree[u] = 1;
    for(edge &e : tree[u]){
        if(p == e.to) continue;
        dfs(e.to, tree, subtree, u);
        subtree[u] += subtree[e.to];
    }
}

void dfs_reroot(int u, vector<edge> tree[], vector<int> &subtree, vector<edge> &edges, const int N, int p = -1){
    for(edge &e : tree[u]){
        if(e.to == p) continue;

        edges[e.idx].paths = N - subtree[e.to];

        subtree[u] -= subtree[e.to];
        subtree[e.to] += subtree[u];

        dfs_reroot(e.to, tree, subtree, edges, N, u);

        subtree[e.to] -= subtree[u];
        subtree[u] += subtree[e.to];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<edge> tree[n + 1];
    vector<edge> edges(2 * n);
    for(int i = 0; i + 1 < n; ++i){
        int a, b; cin >> a >> b;
        tree[a].push_back({a, b, i, 0});
        edges[i] = {a, b, i, 0};
        tree[b].push_back({b, a, i + n, 0});
        edges[i + n] = {b, a, i, 0};

        deg[a]++;
        deg[b]++;
    }

    vector<int> subtree(n + 1);
    dfs(1, tree, subtree);
    dfs_reroot(1, tree, subtree, edges, n);

    sort(edges.begin(), edges.end());

    int ans[n + 1]; fill(ans, ans + n + 1, -1);
    bool used[n + 1] = {};
    bool used_e[n + 1] = {};
    for(edge &e : edges){
        if(used[e.from] || used_e[e.idx]) continue;
        ans[e.from] = e.idx + 1;
        used_e[e.idx] = true;
        used[e.from] = true;
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}
