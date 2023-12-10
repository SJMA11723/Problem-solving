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
        long long arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        if(k > 2){
            cout << "0\n";
            continue;
        }

        long long ans = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            ans = min(ans, arr[i]);
            for(int j = i + 1; j < n; ++j){
                ans = min(ans, abs(arr[i] - arr[j]));
            }
        }
        if(k == 1){
            cout << ans << '\n';
            continue;
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                long long dif = abs(arr[i] - arr[j]);
                long long *upb = upper_bound(arr, arr + n, dif);
                if(upb != arr) ans = min(ans, dif - *(upb - 1));
                if(upb != arr + n) ans = min(ans, *upb - dif);
            }
        }
        cout << ans << '\n';
    }
}
