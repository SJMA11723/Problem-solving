/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

const int MOD = 1e9 + 7;
int fact[MAXN + 1], inv_fact[MAXN + 1];

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

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
    inv_fact[MAXN] = 750007460;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int h, w, n; cin >> h >> w >> n;
    h--, w--;
    vector<pair<int, int>> walls;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        walls.push_back({a, b});
    }
    walls.push_back({h, w});
    sort(walls.begin(), walls.end());

    n++;
    int dp[n] = {};
    for(int i = 0; i < n; ++i){
        int r, c;
        tie(r, c) = walls[i];
        dp[i] = binom(r + c, c);
        for(int j = 0; j < i; ++j){
            dp[i] -= 1ll * binom(r - walls[j].first + c - walls[j].second, r - walls[j].first) * dp[j] % MOD;
            if(dp[i] < 0) dp[i] += MOD;
        }
    }
    cout << dp[n - 1] << '\n';
}
