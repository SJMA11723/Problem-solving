/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 3359232;

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
    int t; cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n < 3) cout << "0\n";
        else cout << ((bin_exp(2, n / 3 + 1) - 1 + MOD) - 1 + MOD) % MOD  << '\n';
    }
}
