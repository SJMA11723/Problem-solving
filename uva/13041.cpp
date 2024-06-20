/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int64_t p, q, L; cin >> p >> q >> L;
        int64_t ans = 0;
        if(729 % q == 0){
            for(int64_t c = 0; c <= L; ++c){
                int64_t k = 729 / q * p - 81 * c;
                if(k < 0) break;
                ans += max(0ll, 1ll*min((L + 4 * k) / 9, (5 * k) / 11) - max((4 * k + 8) / 9, (5 * k - L + 10) / 11) + 1);
            }
        }

        cout << "Case " << tt << ": " << ans << '\n';
    }
}
