/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200001

using namespace std;

vector<int> tree[MAXN];
int64_t dp[MAXN];
int64_t subtree_size[MAXN];

void dfs(int node, int p = -1){
    subtree_size[node] = 1;
    for(int v : tree[node]){
        if(v == p) continue;
        dfs(v, node);
        subtree_size[node] += subtree_size[v];
        dp[node] += dp[v];
    }
    dp[node] += subtree_size[node];
}

void dfs_reroot(int node, int64_t &ans, int p = -1){
    ans = max(ans, dp[node]);

    for(int v : tree[node]){
        if(v == p) continue;


        /// reroot
        subtree_size[node] -= subtree_size[v];
        dp[node] -= dp[v] + subtree_size[v];

        subtree_size[v] += subtree_size[node];
        dp[v] += dp[node] + subtree_size[node];

        /// recursion
        dfs_reroot(v, ans, node);

        /// reverse reroot
        subtree_size[v] -= subtree_size[node];
        dp[v] -= dp[node] + subtree_size[node];

        subtree_size[node] += subtree_size[v];
        dp[node] += dp[v] + subtree_size[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        tree[b].push_back(a);
        tree[a].push_back(b);
    }

    dfs(1);

    int64_t ans = 0;
    dfs_reroot(1, ans);

    cout << ans << '\n';
}
