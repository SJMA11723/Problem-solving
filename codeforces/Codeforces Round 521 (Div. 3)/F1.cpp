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
    int n, k, x; cin >> n >> k >> x;

    int arr[n];
    for(int &x : arr) cin >> x;

    int64_t dp[n + 1][x + 1];
    fill(dp[0], dp[0] + (n + 1) * (x + 1), LLONG_MIN);

    dp[0][x] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < x; ++j){
            for(int l = 1; 0 <= i - l && l <= k; ++l)
                dp[i][j] = max(dp[i][j], dp[i - l][j + 1] + arr[i - 1]);
        }
    }

    int64_t ans = LLONG_MIN;
    for(int i = n - k + 1; i <= n; ++i) ans = max(ans, *max_element(dp[i], dp[i] + x + 1));

    cout << (ans < 0 ? -1 : ans) << '\n';
}
