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
        int x, y, n; cin >> x >> y >> n;
        int r = n % x;
        int ans = n;
        if(r < y){
            ans -= r;
            ans -= x - y;
        } else ans -= r - y;
        cout << ans << '\n';
    }
}
