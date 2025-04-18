/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

const int MOD = 1e9 + 7;

int fact[MAXN + 1], inv_fact[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 556156297;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << 1ll * fact[2 * n] * inv_fact[n + 1] % MOD * inv_fact[n] % MOD << '\n';
    }
}
