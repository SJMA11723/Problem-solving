/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

const long long MOD = 1e9 + 7;

long long bin_exp(long long a, long long b){
    if(!b) return 1;
    a %= MOD;
    long long tmp = bin_exp(a, b / 2);
    if(b % 2) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long fact[MAXN];
    fact[0] = 1;
    for(long long i = 1; i < MAXN; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    long long inv2 = bin_exp(2, MOD - 2);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fact[2 * n] * inv2 % MOD << '\n';
    }
}
