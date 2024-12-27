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
        int64_t l, r, G; cin >> l >> r >> G;
        l = (l + G - 1) / G;
        r /= G;
        if(r < l) cout << "-1 -1\n";
        else if(l == r){
            if(l == 1) cout << G << ' ' << G << '\n';
            else cout << "-1 -1\n";
        } else {
            int64_t A = -1, B = -1;
            for(int64_t i = 0; i <= r - l; ++i){
                for(int j = 0; j <= i; ++j){
                    if(__gcd(l + j, r - (i - j)) == 1){
                        A = (l + j) * G;
                        B = (r - (i - j)) * G;
                        break;
                    }
                }
                if(A != -1) break;
            }
            cout << A << ' ' << B << '\n';
        }
    }
}
