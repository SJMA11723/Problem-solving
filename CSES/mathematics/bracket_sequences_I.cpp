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
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    if(n % 2) cout << "0\n";
    else {
        n >>= 1;
        int fact2n = 1, inv_factn, inv_factn1;
        for(int i = 1; i <= 2 * n; ++i){
            fact2n = 1ll * i * fact2n % MOD;
            if(i == n) inv_factn = bin_exp(fact2n, MOD - 2);
        }
        cout << 1ll * fact2n * inv_factn % MOD * inv_factn % MOD * bin_exp(n + 1, MOD - 2) % MOD << '\n';
    }
}
