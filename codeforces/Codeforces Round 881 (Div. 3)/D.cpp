/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], int subtree_sz[], int p = -1){
    subtree_sz[u] = tree[u].size() == 1 && u;
    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, subtree_sz, u);
        subtree_sz[u] += subtree_sz[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> tree[n];
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int subtree_sz[n] = {};
        dfs(0, tree, subtree_sz);

        int q; cin >> q;
        while(q--){
            int x, y; cin >> x >> y;
            x--, y--;
            cout << 1ll * subtree_sz[x] * subtree_sz[y] << '\n';
        }
    }
}
