/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

const int MOD = 1e9 + 7;
const int inv2 = 500000004;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[MAXN + 1];
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= MAXN; ++i) dp[i] = (dp[i - 1] + 2ll * (i - 1) * dp[i - 2]) % MOD;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        while(k--){
            int r, c; cin >> r >> c;
            n -= 1 + (r != c);
        }
        cout << dp[n] << '\n';
    }
}
