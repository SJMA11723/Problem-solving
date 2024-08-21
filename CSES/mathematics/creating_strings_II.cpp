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

    string s; cin >> s;
    int fact[s.size() + 1];
    fact[0] = 1;
    for(int i = 1; i <= s.size(); ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;

    int inv_fact[s.size() + 1];
    inv_fact[s.size()] = bin_exp(fact[s.size()], MOD - 2);
    for(int i = s.size(); 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int cnt[27] = {};
    for(char c : s) cnt[c - 'a']++;

    int ans = fact[s.size()];
    for(int i = 0; i < 27; ++i) ans = 1ll * ans * inv_fact[cnt[i]] % MOD;
    cout << ans << '\n';
}
