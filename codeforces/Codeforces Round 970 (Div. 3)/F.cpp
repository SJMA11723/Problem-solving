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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0, ans = 0;
        int arr[n];
        for(int &x : arr){
            cin >> x;
            sum += x;
            if(sum >= MOD) sum -= MOD;
        }
        for(int i = 0; i < n; ++i){
            ans += 1ll * arr[i] * (sum - arr[i] + MOD) % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        ans = 1ll * ans * bin_exp(1ll * n * (n - 1) % MOD, MOD - 2) % MOD;

        cout << ans << '\n';
    }
}
