/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll *tmp * tmp % MOD;
}

int fact[MAXN + 1], inv_fact[MAXN + 1];

int binom(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 750007460;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    string s; cin >> s;
    int n = s.size();
    int pref = 0, suff = 0;
    for(int i = 0; i < n; ++i) suff += s[i] == ')';

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            pref++;
            /// restamos 1 para incluir el ultimo '('
            ans += binom(pref + (suff - 1), pref); /// pref 1's, suff 0's -> [0, '('], [1, ')']
            if(ans >= MOD) ans -= MOD;
        } else suff--;
    }
    cout << ans << '\n';
}
