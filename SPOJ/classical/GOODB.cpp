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
    int n, w, t, r; cin >> n >> w >> t >> r;

    int fact[n + 1], inv_fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[n] = bin_exp(fact[n], MOD - 2);
    for(int i = n; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    cout << 1ll * fact[n] * inv_fact[w] % MOD * inv_fact[t] % MOD * inv_fact[r] % MOD << '\n';
}
