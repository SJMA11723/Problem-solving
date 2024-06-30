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
        int l, r; cin >> l >> r;
        int64_t ans = 0;
        while(r){
            ans += r - l;
            r /= 10;
            l /= 10;
        }
        cout << ans << '\n';
    }
}
