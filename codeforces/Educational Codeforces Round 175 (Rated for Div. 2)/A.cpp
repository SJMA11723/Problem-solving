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
        int n; cin >> n;
        if(n < 3){
            cout << n + 1 << '\n';
            continue;
        }
        int ans = 3;
        if(n >= 15) ans += (n / 15 - 1) * 3 + min(2, n % 15) + 1;
        cout << ans << '\n';
    }
}
