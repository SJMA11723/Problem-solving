/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int64_t bin_exp(int a, int64_t b){
    if(!b) return a ? 1 : 0;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        if(n <= 4) cout << n << '\n';
        else if(n % 3 == 1) cout << 4ll * bin_exp(3, (n - 3) / 3) % MOD << '\n';
        else if(n % 3 == 2) cout << 2ll * bin_exp(3, n / 3) % MOD << '\n';
        else cout << bin_exp(3, n / 3) << '\n';
    }
}
