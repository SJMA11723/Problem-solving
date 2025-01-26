/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t pairs(int64_t n){
    return n * (n - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, s, p; cin >> r >> s >> p;
    long double dp[r + 1][s + 1][p + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= r; ++i){
        for(int j = 0; j <= s; ++j){
            for(int k = 0; k <= p; ++k){
                if(i + j + k == i){
                    dp[i][j][k] = 1;
                    continue;
                }
                int64_t s = pairs(i + j + k) - pairs(i) - pairs(j) - pairs(k);
                if(i) dp[i][j][k] += i * k * dp[i - 1][j][k];
                if(j) dp[i][j][k] += i * j * dp[i][j - 1][k];
                if(k) dp[i][j][k] += j * k * dp[i][j][k - 1];
                dp[i][j][k] /= s;
            }
        }
    }
    cout << fixed << setprecision(9) << dp[r][s][p] << ' ';

    memset(dp, 0, sizeof(dp));
    for(int j = 1; j <= s; ++j){
        for(int i = 0; i <= r; ++i){
            for(int k = 0; k <= p; ++k){
                if(i + j + k == j){
                    dp[i][j][k] = 1;
                    continue;
                }
                int64_t s = pairs(i + j + k) - pairs(i) - pairs(j) - pairs(k);
                if(i) dp[i][j][k] += i * k * dp[i - 1][j][k];
                if(j) dp[i][j][k] += i * j * dp[i][j - 1][k];
                if(k) dp[i][j][k] += j * k * dp[i][j][k - 1];
                dp[i][j][k] /= s;
            }
        }
    }
    cout << fixed << setprecision(9) << dp[r][s][p] << ' ';


    memset(dp, 0, sizeof(dp));
    for(int k = 1; k <= p; ++k){
        for(int i = 0; i <= r; ++i){
            for(int j = 0; j <= s; ++j){
                if(i + j + k == k){
                    dp[i][j][k] = 1;
                    continue;
                }
                int64_t s = pairs(i + j + k) - pairs(i) - pairs(j) - pairs(k);
                if(i) dp[i][j][k] += i * k * dp[i - 1][j][k];
                if(j) dp[i][j][k] += i * j * dp[i][j - 1][k];
                if(k) dp[i][j][k] += j * k * dp[i][j][k - 1];
                dp[i][j][k] /= s;
            }
        }
    }
    cout << fixed << setprecision(9) << dp[r][s][p] << '\n';
}
