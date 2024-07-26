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
        int n, x; cin >> n >> x;
        int64_t ans = 0;
        for(int64_t a = 1; a <= x - 2; ++a){
            for(int64_t b = 1; b <= x - a - 1; ++b){
                if(a + b + 1 > x || a * b + a + b > n) break;

                int64_t l = 1, r = x - a - b + 1;
                while(l < r){
                    int64_t mid = l + (r - l) / 2;
                    if(a * b + mid * (a + b) <= n) l = mid + 1;
                    else r = mid;
                }
                ans += l - 1;
            }
        }
        cout << ans << '\n';
    }
}
