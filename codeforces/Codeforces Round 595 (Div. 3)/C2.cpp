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
    while(t--){
        int64_t n; cin >> n;
        int64_t last2 = 0;
        int64_t pow3 = 1;
        int64_t tmp = n;
        int64_t ans = n;
        while(tmp){
            int64_t r = tmp % 3;
            if(r == 2) last2 = pow3;
            pow3 *= 3;
            tmp /= 3;
        }

        if(last2){
            int64_t last0 = 1;
            tmp = n;
            while(1){
                int64_t r = tmp % 3;
                if(!r && last2 < last0){
                    ans += last0;
                    break;
                }
                ans -= r * last0;
                tmp /= 3;
                last0 *= 3;
            }
        }
        cout << ans << '\n';
    }
}
