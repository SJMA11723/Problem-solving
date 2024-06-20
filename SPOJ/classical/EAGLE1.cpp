/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to;
    int64_t dogs;
};

void dfs(int node, int p, vector<edge> tree[], int64_t dp[]){
    for(edge &e : tree[node]){
        if(e.to == p) continue;
        dfs(e.to, node, tree, dp);
        dp[node] = max(dp[node], e.dogs + dp[e.to]);
    }
}

void dfs_reroot(int node, int p, vector<edge> tree[], int64_t dp[], int64_t ans[]){
    ans[node] = dp[node];

    /// Encuentra los dos hijos maximos
    int64_t maxi1 = 0, maxi2 = 0;
    int v_max1 = -1;
    for(edge &e : tree[node]){
        if(e.dogs + dp[e.to] >= maxi1){
            maxi2 = maxi1;
            v_max1 = e.to;
            maxi1 = e.dogs + dp[e.to];
        } else if(e.dogs + dp[e.to] >= maxi2){
            maxi2 = e.dogs + dp[e.to];
        }
    }

    for(edge &e : tree[node]){
        if(e.to == p) continue;

        /// reroot (node -> e.to)
        int64_t rev_dp = dp[node];
        int64_t rev_dp_e = dp[e.to];

        if(e.to == v_max1) dp[node] = maxi2;
        dp[e.to] = max(e.dogs + dp[node], dp[e.to]);

        /// recursion
        dfs_reroot(e.to, node, tree, dp, ans);

        /// reverse reroot
        dp[node] = rev_dp;
        dp[e.to] = rev_dp_e;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<edge> tree[n + 1];
        for(int i = 1; i < n; ++i){
            int a, b, d; cin >> a >> b >> d;
            tree[a].push_back({b, d});
            tree[b].push_back({a, d});
        }

        int64_t dp[n + 1] = {};
        dfs(1, 0, tree, dp);

        int64_t ans[n + 1] = {};
        dfs_reroot(1, 0, tree, dp, ans);

        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
