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
        int n, k, x; cin >> n >> k >> x;
        int arr[n + 1]; arr[0] = 0;
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        sort(arr + 1, arr + n + 1, greater<int>());
        for(int i = 1; i <= n; ++i) arr[i] += arr[i - 1];
        int ans = INT_MIN;
        for(int i = 0; i <= min(n, k); ++i) ans = max(ans, arr[n] - arr[i] - 2 * (arr[min(i + x, n)] - arr[i]));
        cout << ans << '\n';
    }
}
