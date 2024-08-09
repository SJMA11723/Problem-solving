/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define lsb(S) ((S) & -(S))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--){
        int64_t l, r; cin >> l >> r;
        int64_t ans = r, cnt_bits = __builtin_popcountll(r);
        while(r){
            if(r - 1 >= l && __builtin_popcountll(r - 1) >= cnt_bits){
                ans = __builtin_popcount(r - 1);
                ans = r - 1;
            }
            r -= lsb(r);
        }
        cout << ans << '\n';
    }
}
