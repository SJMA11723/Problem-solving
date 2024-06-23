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
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n);
        int ans = 1, cnt = 1;
        for(int i = 1; i < n; ++i){
            if(arr[i] - arr[i - 1] > k){
                ans = max(ans, cnt);
                cnt = 1;
            } else cnt++;
        }
        ans = max(ans, cnt);
        ans = n - ans;
        cout << ans << '\n';
    }
}
