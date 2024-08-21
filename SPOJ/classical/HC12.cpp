/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10000

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
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
    inv_fact[MAXN] = bin_exp(fact[MAXN], MOD - 2);
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + n);
        int ans = 0;
        for(int i = k - 1; i < n; ++i){
            ans += 1ll * arr[i] * fact[i] % MOD * inv_fact[k - 1] % MOD * inv_fact[i - k + 1] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}
