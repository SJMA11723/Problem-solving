#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long dp[1000001], ac[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long k; cin >> k;

    dp[1] = 1;
    ac[1] = 1;
    dp[2] = 1;
    ac[2] = 2;

    for(int i = 3; i <= k; ++i){
      dp[i] = (ac[i - 1] - ac[i - i / 2 - 1] + MOD) % MOD;
      ac[i] = (dp[i] + ac[i - 1]) % MOD;
      //cout << dp[i] << ' ';
    }

    cout << dp[k];
}