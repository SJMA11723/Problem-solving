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
        sort(arr, arr + n);
        int64_t cnt = 0, ans = 0;
        for(int i = 0; i < n && cnt < k; ++i){
            if(i){
                arr[i] -= arr[i - 1];
                ans++;
            }

            int64_t cnt_press = min(1ll*arr[i], (k - cnt + n - i - 1) / (n - i));
            cnt_press = min(cnt_press * (n - i), k - cnt);
            cnt += cnt_press;
            ans += cnt_press;

            if(i) arr[i] += arr[i - 1];
        }
        cout << ans << '\n';
    }
}
