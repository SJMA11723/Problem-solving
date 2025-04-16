/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXK 30
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int ans = 0, pow2 = 1;
    for(int k = 0; k <= MAXK; ++k){
        int cnt_1 = 0;
        bool sum = 0;
        for(int i = 0; i < n; ++i){
            if(is_on(arr[i], k)) sum ^= 1;

            if(sum) ans += 1ll * (i + 1 - cnt_1) * (i + 2) % MOD * pow2 % MOD;
            else ans += 1ll * cnt_1 * (i + 2) % MOD * pow2 % MOD;
            if(ans >= MOD) ans -= MOD;

            cnt_1 += sum;
        }

        sum = 0, cnt_1 = 0;
        for(int i = n - 1; 0 <= i; --i){
            if(is_on(arr[i], k)) sum ^= 1;

            if(sum) ans -= 1ll * (n - i - cnt_1) * (i + 1) % MOD * pow2 % MOD;
            else ans -= 1ll * cnt_1 * (i + 1) % MOD * pow2 % MOD;
            if(ans < 0) ans += MOD;

            cnt_1 += sum;
        }

        pow2 <<= 1;
        if(pow2 >= MOD) pow2 -= MOD;
    }
    cout << ans << '\n';
}
