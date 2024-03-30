/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int64_t M;
vector<int> tree[MAXN];
int64_t dp[MAXN];
int64_t ans[MAXN];

void dfs(int node, int p = 0){
    dp[node] = 1;
    for(int v : tree[node]){
        if(v == p) continue;
        dfs(v, node);

        dp[node] = dp[node] * (dp[v] + 1) % M;
    }
}


void dfs_reroot(int node, int p = 0){
    ans[node] = dp[node];

    vector<int64_t> pref, suff;
    pref.push_back(1);

    int64_t prod_p = 1, prod_s = 1;
    for(int i = 0; i < tree[node].size(); ++i){
        int v = tree[node][i];
        prod_p *= dp[v] + 1;
        prod_s *= dp[ *(tree[node].end() - 1 - i) ] + 1;
        prod_p %= M;
        prod_s %= M;
        pref.push_back(prod_p);
        suff.push_back(prod_s);
    }
    suff.push_back(1);
    reverse(suff.begin(), suff.end());
    suff.push_back(1);


    int idx = 1;
    for(int v : tree[node]){
        if(v == p){
            idx++;
            continue;
        }

        /// reroot
        int64_t rev_dpv = dp[v];

        dp[node] = pref[idx - 1] * suff[idx + 1] % M;
        dp[v] *= dp[node] + 1;
        dp[v] %= M;

        ///recursion
        dfs_reroot(v, node);

        /// reverse reroot
        dp[node] = pref.back();
        dp[v] = rev_dpv;

        idx++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n >> M;
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);
    dfs_reroot(1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}
