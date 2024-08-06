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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        ans += 2 * ((a > c && b >= d) || (a >= c && b > d));
        ans += 2 * ((a > d && b >= c) || (a >= d && b > c));
        cout << ans << '\n';
    }
}
