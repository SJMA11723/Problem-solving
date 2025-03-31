/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[60] = {};
    for(int i = 0; i < n; ++i){
        int64_t x; cin >> x;
        int exp2 = 0;
        while(x){
            if(x & 1) cnt[exp2]++;
            x >>= 1;
            exp2++;
        }
    }

    int ans = 0, pow2 = 1;
    for(int i = 0; i < 60; ++i){
        ans += 1ll * cnt[i] * (n - cnt[i]) % MOD * pow2 % MOD;
        if(ans >= MOD) ans -= MOD;

        pow2 <<= 1;
        if(pow2 >= MOD) pow2 -= MOD;
    }
    cout << ans << '\n';
}
