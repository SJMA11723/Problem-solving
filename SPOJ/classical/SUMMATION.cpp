/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        int pow2 = 1;
        for(int i = 1; i < n; ++i){
            pow2 <<= 1;
            if(pow2 >= MOD) pow2 -= MOD;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            ans += 1ll * x * pow2 % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        cout << "Case " << tt << ": " << ans << '\n';
    }
}
