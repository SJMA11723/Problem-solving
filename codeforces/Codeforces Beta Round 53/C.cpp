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
    int n; cin >> n;

    int ans = 1;
    for(int i = 1; i < 2 * n; ++i){
        ans = 1ll * i * ans % MOD;
        if(i == n){
            int inv_n = bin_exp(ans, MOD - 2);
            ans = 1ll * ans * inv_n % MOD * inv_n % MOD * n % MOD;
        }
    }
    ans += (ans + MOD - n) % MOD;
    if(ans >= MOD) ans -= MOD;
    cout << ans << '\n';
}
