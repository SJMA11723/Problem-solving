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
    int n, m, k; cin >> n >> m >> k;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    arr[0] = 0;
    for(int i = 1; i <= k; ++i) arr[i] += arr[i - 1];

    int offer[n + 1] = {};
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        if(x <= n) offer[x] = max(offer[x], y);
    }

    int dp[k + 1];
    dp[0] = 0;
    for(int i = 1; i <= k; ++i){
        dp[i] = dp[i - 1] + arr[i] - arr[i - 1];
        for(int j = 1; j <= i; ++j)
            dp[i] = min(dp[i], dp[i - j] + arr[i] - arr[i - j + offer[j]]);
    }

    cout << dp[k];
}
