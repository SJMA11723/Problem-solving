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
        int64_t n, m; cin >> n >> m;
        int arr[n];
        for(int &x : arr) cin >> x;

        sort(arr, arr + n);
        int64_t sum = 0, ans = 0;
        int l = 0;
        for(int r = 0; r < n; ++r){
            sum += arr[r];
            while(l < n && (sum > m || arr[r] - arr[l] > 1)) sum -= arr[l++];
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
}
