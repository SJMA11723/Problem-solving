/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define MAXLOGN 17

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int ans = 0, pow2 = 1;
    for(int k = 0; k < MAXLOGN; ++k){
        int cnt_a = 0;
        for(int i = 0; i < n; ++i){
            if(is_on(a[i], k)) cnt_a++;
        }

        for(int i = 0; i < n; ++i){
            if(is_on(b[i], k)){
                ans += 1ll * (n - cnt_a) * fact[n - 1] % MOD * pow2 % MOD;
                if(ans >= MOD) ans -= MOD;
            } else {
                ans += 1ll * cnt_a * fact[n - 1] % MOD * pow2 % MOD;
                if(ans >= MOD) ans -= MOD;
            }
        }

        pow2 <<= 1;
        if(pow2 >= MOD) pow2 -= MOD;
    }
    cout << ans << '\n';
}
