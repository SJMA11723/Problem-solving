/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t bin_exp(int64_t a, int64_t b){
    if(!b) return 1;
    int64_t tmp = bin_exp(a, b / 2);
    if(b % 2) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r, k; cin >> l >> r >> k;
        cout << (bin_exp(9 / k + 1, r) - bin_exp(9 / k + 1, l) + MOD) % MOD << '\n';
    }
}
