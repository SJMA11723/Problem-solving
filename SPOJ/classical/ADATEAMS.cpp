/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000000

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
    int fact[MAXN + 1], inv_fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = bin_exp(fact[MAXN], MOD - 2);
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int n, a, b, d;

    while(cin >> n >> a >> b >> d)
    cout << 1ll * fact[n] * inv_fact[a] % MOD * inv_fact[n - a] % MOD * bin_exp(1ll * fact[b] * inv_fact[d] % MOD * inv_fact[b - d] % MOD, a) % MOD << '\n';
}
