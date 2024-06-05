/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string, int> mask_g;
        map<string, int> mask_w;
        pair<string, string> names[n];
        for(int i = 0; i < n; ++i){
            pair<string, string> p;
            cin >> p.first >> p.second;
            mask_g[p.first] = mask_g[p.first] | (1 << i);
            mask_w[p.second] = mask_w[p.second] | (1 << i);
            names[i] = p;
        }

        bool adj[n][n];
        memset(adj, 0, sizeof(adj));
        for(int i = 0; i < n; ++i){
            int cur_mask_g = mask_g[names[i].first];
            int cur_mask_w = mask_w[names[i].second];
            for(int j = 0; j < n; ++j){
                if(is_on(cur_mask_g, j) || is_on(cur_mask_w, j)) adj[i][j] = 1;
                //cout << adj[i][j] << ' ';
            }
            //cout << '\n';
        }

        bool dp[1 << n][n];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i) dp[1 << i][i] = true;

        int ans = 1;

        for(int mask = 1; mask < (1 << n); ++mask){
            for(int u = 0; u < n; ++u){
                if(!is_on(mask, u)) continue;

                for(int v = 0; v < n; ++v){
                    if(!adj[u][v] || !is_on(mask, v)) continue;

                    dp[mask][u] = dp[mask][u] || dp[mask ^ (1 << u)][v];
                }

                if(dp[mask][u]) ans = max(ans, __builtin_popcount(mask));
            }
        }


        cout << n - ans << '\n';
    }
}
