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
        int ans = INT_MAX;
        for(int i = 1; i <= 20; ++i){
            int cnt0 = (((r + 1) >> i) << (i - 1)) + min(1 << (i - 1), (r + 1) % (1 << i));
            cnt0 -= ((l >> i) << (i - 1)) + min(1 << (i - 1), l % (1 << i));
            ans = min(ans, cnt0);
        }
        cout << ans << '\n';
    }
}
