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
        int cnt1 = 0, cntm1 = 0;
        while(n--){
            int x; cin >> x;
            if(x < 0) cntm1++;
            else cnt1++;
        }

        int ans = 0;
        if(cnt1 < cntm1){
            ans = (cntm1 - cnt1 + 1) / 2;
            cntm1 -= ans;
        }
        if(cntm1 % 2) ans++;
        cout << ans << '\n';
    }
}
