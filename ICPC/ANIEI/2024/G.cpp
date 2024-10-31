#include <bits/stdc++.h>

using namespace std;

int64_t dfs(int u, vector<int> tree[], int64_t bonus[], int64_t bonus_chain[], int64_t bonus_subtree[], int p = -1){
    int64_t bonus_back_prop = 0;
    bonus_subtree[u] = 0;

    for(int v : tree[u]){
        if(v == p) continue;
        bonus_back_prop += dfs(v, tree, bonus, bonus_chain, bonus_subtree, u);
        bonus_subtree[u] += bonus_subtree[v];
    }
    bonus_back_prop += bonus_chain[u];
    bonus[u] += bonus_back_prop;
    bonus_subtree[u] += bonus[u];

    return bonus_back_prop;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<int> tree[n];
    int root;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x){
            x--;
            tree[x].push_back(i);
        } else root = i;
    }

    int64_t bonus[n] = {};
    int64_t bonus_chain[n] = {};
    int64_t bonus_subtree[n] = {};
    for(int i = 0; i < m; ++i){
        int m, e, v; cin >> m >> e >> v;
        e--;
        if(m == 1) bonus[e] += v;
        else bonus_chain[e] += v;
    }

    dfs(root, tree, bonus, bonus_chain, bonus_subtree);

    while(q--){
        int t, u; cin >> t >> u;
        u--;
        if(t == 1) cout << bonus[u] << '\n';
        else cout << bonus_subtree[u] << '\n';
    }
}
