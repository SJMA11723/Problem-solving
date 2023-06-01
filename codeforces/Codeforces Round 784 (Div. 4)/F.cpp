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
        int arr[n + 1];
        int acL[n + 1] = {}, acR[n + 1] = {};
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            acL[i] = acL[i - 1] + arr[i];
        }
        for(int i = n; 0 < i; --i) acR[n - i + 1] = acR[n - i] + arr[i];

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            int pos = lower_bound(acR, acR + n + 1 - i, acL[i]) - acR;
            if(pos < n + 1 - i && acR[pos] == acL[i]) ans = max(ans, i + pos);
        }
        cout << ans << '\n';
    }
}
