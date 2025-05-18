/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define MAXN 5000

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int fact[MAXN + 1], inv_fact[MAXN + 1];

int binom(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 387029115;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int n, m, k; cin >> n >> m >> k;

    int dp[k + 1] = {};
    dp[1] = 1;
    for(int i = 2; i <= k; ++i){
        dp[i] = bin_exp(i, n);
        for(int j = 1; j < i; ++j){
            dp[i] -= 1ll * binom(i, j) * dp[j] % MOD;
            if(dp[i] < 0) dp[i] += MOD;
        }
    }

    cout << 1ll * dp[k] * binom(m, k) % MOD << '\n';
}
