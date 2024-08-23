/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXN + 1], inv_fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 52180388;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int k; cin >> k;
    int ans = 1, sum; cin >> sum; k--;
    while(k--){
        int x; cin >> x;
        ans = 1ll * ans * fact[sum + x - 1] % MOD * inv_fact[x - 1] % MOD * inv_fact[sum] % MOD;
        sum += x;
    }
    cout << ans << '\n';
}
