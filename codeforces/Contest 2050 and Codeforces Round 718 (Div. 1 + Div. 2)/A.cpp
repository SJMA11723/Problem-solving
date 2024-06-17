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
        if(n % 2050) cout << "-1\n";
        else {
            n /= 2050;
            int ans = 0;
            while(n){
                ans += n % 10;
                n /= 10;
            }
            cout << ans << '\n';
        }
    }
}
