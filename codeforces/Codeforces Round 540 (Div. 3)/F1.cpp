/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], int color[], vector<vector<int>> &dp, int p = -1){
    if(color[u] == 1) dp[u][0]++;
    else if(color[u] == 2) dp[u][1]++;

    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, color, dp, u);
        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][1];
    }
}

void dfs_reroot(int u, vector<int> tree[], vector<vector<int>> &dp, int &ans, int p = -1){
    for(int v : tree[u]){
        if(v == p) continue;

        dp[u][0] -= dp[v][0];
        dp[u][1] -= dp[v][1];

        if(!(dp[v][0] && dp[v][1]) && !(dp[u][0] && dp[u][1])) ans++;

        dp[v][0] += dp[u][0];
        dp[v][1] += dp[u][1];

        dfs_reroot(v, tree, dp, ans, u);

        dp[v][0] -= dp[u][0];
        dp[v][1] -= dp[u][1];

        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int color[n];
    for(int &c : color) cin >> c;

    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<vector<int>> dp(n, vector<int>(2));
    dfs(0, tree, color, dp);

    int ans = 0;
    dfs_reroot(0, tree, dp, ans);
    cout << ans << '\n';
}
