/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[2][1001], ans[1001] = {};
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 1000; ++i){
        bool i1 = i & 1;
        dp[i1][0] = 0;
        for(int j = 1; j <= i; ++j) dp[i1][j] = (1ll * j * dp[i1 ^ 1][j] + dp[i1 ^ 1][j - 1]) % MOD;

        for(int j = 1; j <= i; ++j){
            ans[i] += dp[i1][j];
            if(ans[i] >= MOD) ans[i] -= MOD;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
