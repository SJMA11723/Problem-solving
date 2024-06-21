/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t ans = LLONG_MAX;
    for(int k = log10(n); k <= 10; ++k){
        for(int mask = 0; mask < (1 << k); ++mask){
            if(2 * __builtin_popcount(mask) != k) continue;
            int64_t num = 0, pot = 1;
            for(int i = 0; i < k; ++i){
                num += (is_on(mask, i) ? 4 : 7) * pot;
                pot *= 10;
            }
            if(num >= n) ans = min(ans, num);
        }
    }
    cout << ans << '\n';
}
