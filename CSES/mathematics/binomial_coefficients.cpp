/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 1000000

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    return 1ll * tmp * tmp % MOD * (b % 2 ? a : 1) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXVAL + 1], inv_fact[MAXVAL + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXVAL; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;

    inv_fact[MAXVAL] = bin_exp(fact[MAXVAL], MOD - 2);
    for(int i = MAXVAL; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        cout << 1ll * fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD << '\n';
    }
}
