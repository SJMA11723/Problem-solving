/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 2001

using namespace std;

const int MOD = 1e9 + 7;
int dp[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;

    dp[1][0] = 1;

    for(int l = 1; l <= k; ++l){
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; j += i) dp[j][l] = (dp[j][l] + dp[i][l - 1]) % MOD;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = (ans + dp[i][k]) % MOD;
    cout << ans << '\n';
}
