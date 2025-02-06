/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int dp[], vector<int> tree[], bool color[], int p = -1){
    dp[u] = color[u] ? 1 : -1;
    for(int v : tree[u])
    if(v != p){
        dfs(v, dp, tree, color, u);
        dp[u] += max(0, dp[v]);
    }
}

void dfs_reroot(int u, int ans[], int dp[], vector<int> tree[], bool color[], int p = -1){
    ans[u] = dp[u];
    for(int v: tree[u]){
        if(v == p) continue;

        dp[u] -= max(0, dp[v]);
        dp[v] += max(0, dp[u]);
        dfs_reroot(v, ans, dp, tree, color, u);
        dp[v] -= max(0, dp[u]);
        dp[u] += max(0, dp[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    bool color[n];
    for(bool &x : color) cin >> x;

    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int dp[n];
    dfs(0, dp, tree, color);

    int ans[n];
    dfs_reroot(0, ans, dp, tree, color);

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
