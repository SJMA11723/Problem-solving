/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    int fact[n + m], inv_fact[n + m];
    fact[0] = 1;
    for(int i = 1; i <= n + m; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
    inv_fact[n + m - 1] = bin_exp(fact[n + m - 1], MOD - 2);
    for(int i = n + m - 1; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    cout << 1ll * fact[n + m - 1] * inv_fact[n - 1] % MOD * inv_fact[m] % MOD << '\n';
}
