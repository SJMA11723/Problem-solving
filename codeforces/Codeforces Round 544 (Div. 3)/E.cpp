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
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    int len[n + 1], l = 0;
    for(int r = 0; r < n; ++r){
        while(l < r && arr[r] - arr[l] > 5) l++;
        len[r + 1] = r - l + 1;
    }

    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= k; ++i){
        for(int j = 1; j <= n; ++j)
            dp[i % 2][j] = max({dp[i % 2][j - 1], dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - len[j]] + len[j]});
    }

    cout << dp[k % 2][n] << '\n';
}
