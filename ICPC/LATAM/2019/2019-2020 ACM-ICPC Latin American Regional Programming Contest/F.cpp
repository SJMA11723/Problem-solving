#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int S, n; cin >> S >> n;

    int dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) dp[i][1] = 1;

    for(int i = 2; i <= S; ++i){
        for(int b = 0; b <= n; ++b){
            for(int M = 0; M <= b; M += i){
                dp[b][i] += dp[b - M][i - 1];
                if(dp[b][i] >= MOD) dp[b][i] -= MOD;
            }

            cout << dp[b][i] << ' ';
        }
        cout << '\n';
    }


    int ans = 0;
    for(int i = 0; i <= S; ++i){
        for(int j = 0; j <= n; ++j){
            ans += 1ll * dp[j - i][i] * dp[n - j - S + i][S - i] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}
