/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], vector<int> &etour, int t_in[], int sz_subtree[]){
    t_in[u] = etour.size();
    etour.push_back(u);
    sz_subtree[u] = 1;
    for(int v : tree[u]){
        dfs(v, tree, etour, t_in, sz_subtree);
        sz_subtree[u] += sz_subtree[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> tree[n + 1];
    for(int i = 2; i <= n; ++i){
        int x; cin >> x;
        tree[x].push_back(i);
    }

    for(int i = 1; i <= n; ++i) sort(tree[i].begin(), tree[i].end());

    int t_in[n + 1], sz_subtree[n + 1];
    vector<int> etour;
    dfs(1, tree, etour, t_in, sz_subtree);

    while(q--){
        int u, k; cin >> u >> k;
        if(sz_subtree[u] < k) cout << "-1\n";
        else cout << etour[t_in[u] + k - 1] << '\n';
    }
}
