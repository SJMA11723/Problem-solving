/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h; cin >> n >> h;
    int64_t dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            for(int k = 0; k < i; ++k){
                dp[i][j] += dp[k][j - 1] * dp[i - 1 - k][j - 1];
                for(int r = 0; r <= j - 2; ++r) dp[i][j] += 2 * dp[k][j - 1] * dp[i - 1 - k][r];
            }
        }
    }
    int64_t ans = 0;
    for(int i = h; i <= n; ++i) ans += dp[n][i];
    cout << ans << '\n';
}
