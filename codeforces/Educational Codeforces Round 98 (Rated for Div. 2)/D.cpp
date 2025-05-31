/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 998244353;

int bin_exp(int a, int64_t b){
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

    int sum_odd = 0, sum_even = 1;
    for(int i = 1; i <= n; ++i){
        if(i & 1){
            sum_odd += sum_even;
            if(sum_odd >= MOD) sum_odd -= MOD;
        } else{
             sum_even += sum_odd;
             if(sum_even >= MOD) sum_even -= MOD;
        }
    }
    cout << 1ll * ((n & 1) ? sum_even : sum_odd) * bin_exp(2, 1ll * n * (MOD - 2)) % MOD << '\n';
}
