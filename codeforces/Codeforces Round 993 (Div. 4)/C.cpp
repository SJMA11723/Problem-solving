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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int ans = 0;
        ans += m - max(0, m - a);
        ans += m - max(0, m - b);
        ans += (2 * m - ans) - max(0, (2 * m - ans) - c);
        cout << ans << '\n';
    }
}
