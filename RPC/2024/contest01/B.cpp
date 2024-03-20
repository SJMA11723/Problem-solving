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
    int n, c; cin >> c >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    bool dp[c + 1][c + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = true;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= c; ++j){
            for(int k = 0; k <= c; ++k){
                dp[j][k][i % 2] = dp[j][k][(i - 1) % 2];
                if(j >= arr[i]) dp[j][k][i % 2] = dp[j][k][i % 2] || dp[j - arr[i]][k][(i - 1) % 2];
                if(k >= arr[i]) dp[j][k][i % 2] = dp[j][k][i % 2] || dp[j][k - arr[i]][(i - 1) % 2];
            }
        }
    }

    int sum = INT_MIN, diff = INT_MAX;
    for(int i = 0; i <= c; ++i){
        for(int j = 0; j <= c; ++j){
            if(!dp[i][j][n % 2]) continue;
            if(i + j > sum){
                sum = i + j;
                diff = abs(i - j);
            } else if(i + j == sum && abs(i - j) < diff) diff = abs(i - j);
        }
    }
    cout << (sum + diff) / 2 << ' ' << (sum - diff) / 2 << '\n';
}
