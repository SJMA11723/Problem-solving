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
        int x, y; cin >> x >> y;
        int ans = y / 2;
        x = max(0, x - ans * 7);
        if(y % 2){
            ans++;
            x = max(0, x - 11);
        }
        ans += (x + 14) / 15;

        cout << ans << '\n';
    }
}
