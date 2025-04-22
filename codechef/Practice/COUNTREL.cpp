/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8 + 7;

int bin_exp(int a, int64_t b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        cout << 1ll * (bin_exp(3, n) - bin_exp(2, n + 1) + 1 + MOD) * inv(2) % MOD << ' '
             << 1ll * (bin_exp(4, n) - bin_exp(3, n + 1) + 3ll * bin_exp(2, n) - 1 + MOD) * inv(2) % MOD << '\n';
    }
}
