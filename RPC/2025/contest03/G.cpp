#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;

    const int MAXK = sqrt(8 * n + 1) + 15;
    int dp[n + 1][MAXK + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;

    for(int i = 0; i < n; ++i){
        if(s[i] == '#') continue;
        for(int j = 1; j < MAXK; ++j){
            dp[i + 1][j] += dp[i][j];
            if(dp[i + 1][j] >= MOD) dp[i + 1][j] -= MOD;

            int nxt = min(n, i + j + 1);
            dp[nxt][j + 1] += dp[i][j];
            if(dp[nxt][j + 1] >= MOD) dp[nxt][j + 1] -= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i <= MAXK; ++i){
        ans += dp[n][i];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
