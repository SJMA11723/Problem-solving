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
        int n, m, k; cin >> n >> m >> k;
        int arr[n], arr2[m];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        for(int i = 0; i < m; ++i) cin >> arr2[i];

        sort(arr, arr + n, greater<int>());
        sort(arr2, arr2 + m);

        int idx = -1, ans = 0;
        for(int i = 0; i < n; ++i){
            while(idx + 1 < m && arr2[idx + 1] + arr[i] <= k) idx++;
            ans += idx + 1;
        }

        cout << ans << '\n';
    }
}
