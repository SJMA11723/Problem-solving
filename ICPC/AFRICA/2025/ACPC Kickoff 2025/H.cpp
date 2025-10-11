/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
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
        int n; cin >> n;
        int sum = 0, sum2 = 0;
        for(int i = 1; i <= n; ++i){
            int x; cin >> x;
            sum += x;
            if(sum >= MOD) sum -= MOD;

            sum2 += inv(__gcd(n, i));
            if(sum2 >= MOD) sum2 -= MOD;
        }
        cout << 1ll * sum * sum2 % MOD * inv(n) % MOD << '\n';
    }
}
