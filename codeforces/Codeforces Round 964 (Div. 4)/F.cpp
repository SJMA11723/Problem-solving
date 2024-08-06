/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

const int MOD = 1e9 + 7;
int fact[MAXVAL + 1];

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int combi(int n, int k){
    if(k > n) return 0;
    return 1ll * fact[n] * bin_exp(fact[k], MOD - 2) % MOD * bin_exp(fact[n - k], MOD - 2) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXVAL; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int pos = (k + 1) / 2, one = 0, zero = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x) one++;
            else zero++;
        }

        int ans = 0;
        for(int i = 0; i < pos; ++i){
            ans += 1ll * combi(zero, i) * combi(one, k - i) % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        cout << ans << '\n';
    }
}
