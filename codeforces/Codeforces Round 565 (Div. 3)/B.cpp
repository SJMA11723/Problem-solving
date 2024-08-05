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
        int r1 = 0, r2 = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 3 == 0) ans++;
            else if(x % 3 == 1) r1++;
            else r2++;
        }

        ans += min(r1, r2) + abs(r2 - r1) / 3;
        cout << ans << '\n';
    }
}
