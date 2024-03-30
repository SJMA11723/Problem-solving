/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100002
#define LOGN 17
#define is_on(n, j) ((n) & (1 << (j)))

using namespace std;

vector<int> tree[MAXN];
int subtree_size[MAXN], depth[MAXN], P[LOGN + 1][MAXN];
bool big[MAXN];
vector<pair<int, int>> queries[MAXN];
int ans[MAXN], cnt[MAXN];

void precalc(int node, int  p = 0){
    subtree_size[node] = 1;
    depth[node] = depth[p] + 1;

    P[0][node] = p;
    for(int i = 1; i <= LOGN; ++i)
        P[i][node] = P[i - 1][P[i - 1][node]];

    for(int v : tree[node]){
        if(v == p) continue;
        precalc(v, node);
        subtree_size[node] += subtree_size[v];
    }
}

int kth_ancestor(int node, int k){
    for(int i = LOGN; 0 <= i; --i)
        if(is_on(k, i)) node = P[i][node];
    return node;
}

/// sack
void add(int node, int x, int p = 0){
    cnt[depth[node]] += x;

    for(int v: tree[node])
        if(v != p && !big[v])
            add(v, x, node);
}

void dfs(int node, bool keep, int p = 0){
    int maxi = -1, big_child = -1;
    for(int v : tree[node])
       if(v != p && subtree_size[v] > maxi)
          maxi = subtree_size[v], big_child = v;

    for(int v : tree[node])
        if(v != p && v != big_child)
            dfs(v, false, node);
    if(big_child != -1)
        dfs(big_child, true, node), big[big_child] = 1;

    add(node, 1, p);

    for(auto [v, idx] : queries[node])
        ans[idx] = cnt[ depth[v] ] - 1;

    if(big_child != -1) big[big_child] = 0;
    if(!keep) add(node, -1, p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> roots;
    for(int i = 1; i <= n; ++i){
        int r; cin >> r;
        if(r) tree[r].push_back(i);
        else roots.push_back(i);
    }

    for(int r : roots) precalc(r);

    int m; cin >> m;
    for(int i = 0; i < m; ++i){
        int v, p; cin >> v >> p;
        queries[ kth_ancestor(v, p) ].push_back({v, i});
    }

    for(int r : roots) dfs(r, false);

    for(int i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << '\n';
}
