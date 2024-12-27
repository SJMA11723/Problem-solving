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
        int s; cin >> s;
        int64_t ans = 0;
        while(s){
            int pow10 = 1;
            while(1ll * pow10 * 10 <= s) pow10 *= 10;
            ans += pow10;
            s -= pow10 - pow10 / 10;
        }
        cout << ans << '\n';
    }
}
