/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> tree[], int dist_root[], int dp[], int p = -1){
    for(int v : tree[node]){
        if(v == p) continue;
        dist_root[v] = dist_root[node] + 1;
        dfs(v, tree, dist_root, dp, node);
        dp[node] = max(dp[node], dp[v] + 1);
    }
    /*cout << "NODE " << node + 1 << '\n';
    cout << "    Dist " << dist_root[node] << '\n';
    cout << "    dp " << dp[node] << '\n';*/
}

int64_t k, c;

void dfs_reroot(int node, vector<int> tree[], int dist_root[], int dp[], int64_t &ans, int p = -1){
    ans = max(ans, k * dp[node] - c * dist_root[node]);

    /// encuentra primeras dos hojas mas lejanas
    int maxi1 = 0, maxi2 = 0, v_maxi1 = -1, v_maxi2 = -1;
    for(int v : tree[node]){
        if(dp[v] + 1 >= maxi1){
            maxi2 = maxi1;
            v_maxi2 = v_maxi1;
            maxi1 = dp[v] + 1;
            v_maxi1 = v;
        } else if(dp[v] + 1 >= maxi2){
            maxi2 = dp[v] + 1;
            v_maxi2 = v;
        }
    }

    for(int v : tree[node]){
        if(v == p) continue;

        /// reroot
        int val_dp = dp[node];
        int val_dp_v = dp[v];

        if(v == v_maxi1)
            dp[node] = maxi2;
        dp[v] = max(dp[v], dp[node] + 1);

        /// dfs reroot
        dfs_reroot(v, tree, dist_root, dp, ans, node);

        /// undo reroot
        dp[node] = val_dp;
        dp[v] = val_dp_v;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n >> k >> c;
        vector<int> tree[n];
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int dist_root[n] = {};
        int dp[n] = {};
        dfs(0, tree, dist_root, dp);

        int64_t ans = LLONG_MIN;
        dfs_reroot(0, tree, dist_root, dp, ans);

        cout << ans << '\n';
    }
}
