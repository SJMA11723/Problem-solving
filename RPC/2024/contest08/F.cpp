#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

const int MOD = 1e9 + 7;
int dp[MAXN + 1];
int ans[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    dp[1] = 1;
    if(2 <= n){
        dp[2] = 1;
        ans[2] = 1;
    }

    for(int i = 3; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
        if(dp[i] >= MOD) dp[i] -= MOD;
        if(dp[i] >= MOD) dp[i] -= MOD;

        ans[i] = (1ll * ans[i - 1] + dp[i - 1] + ans[i - 2] + dp[i - 2]) % MOD;
    }

    while(q--){
        int l, r; cin >> l >> r;
        cout << ans[r - l + 1] << '\n';
    }
}
