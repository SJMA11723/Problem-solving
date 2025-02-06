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
    int n, h, l, r; cin >> n >> h >> l >> r;
    int a[n];
    for(int &x : a) cin >> x;

    int dp[n][h];
    memset(dp, 0, sizeof(dp));

    fill(dp[0], dp[0] + h, INT_MIN);
    dp[0][a[0]] = (l <= a[0] && a[0] <= r);
    dp[0][a[0] - 1] = (l <= a[0] - 1 && a[0] - 1 <= r);

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < h; ++j){
            dp[i][j] = max(dp[i - 1][(j - a[i] + h) % h], dp[i - 1][(j - a[i] + 1 + h) % h]) + (l <= j && j <= r);
        }
    }
    cout << *max_element(dp[n - 1], dp[n - 1] + h) << '\n';
}
