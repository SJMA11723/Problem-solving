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
        int arr[n];
        for(int &x : arr) cin >> x;
        int64_t ans = 0;
        int maxi = arr[0];
        for(int i = 1; i < n; ++i){
            if(1ll * arr[i] * maxi < 0){
                ans += maxi;
                maxi = arr[i];
            }
            maxi = max(maxi, arr[i]);
        }
        ans += maxi;
        cout << ans << '\n';
    }
}
