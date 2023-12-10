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
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < k; ++i)
            if(arr[i] < 2 * arr[i + 1]) cnt++;
        if(cnt == k) ans++;

        for(int i = k; i + 1 < n; ++i){
            if(arr[i - k] < 2 * arr[i - k + 1]) cnt--;
            if(arr[i] < 2 * arr[i + 1]) cnt++;
            if(cnt == k) ans++;
        }
        cout << ans << '\n';
    }
}
