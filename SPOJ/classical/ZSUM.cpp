/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e7 + 7;

int64_t bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    while(n && k){
        cout << (bin_exp(n, k) + bin_exp(n, n) + 2 * bin_exp(n - 1, k) + 2 * bin_exp(n - 1, n - 1)) % MOD << '\n';
        cin >> n >> k;
    }
}
