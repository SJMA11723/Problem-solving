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
        for(int &x : arr) cin >> x;
        sort(arr, arr + n, greater<int>());
        for(int i = 1; i < n; i += 2){
            int cnt = min(k, arr[i - 1] - arr[i]);
            arr[i] += cnt;
            k -= cnt;
        }

        int64_t ans = 0;
        for(int i = 0; i < n; ++i){
            if(i % 2) ans -= arr[i];
            else ans += arr[i];
        }
        cout << ans << '\n';
    }
}
