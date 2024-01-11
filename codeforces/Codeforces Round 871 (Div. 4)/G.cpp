/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 2024

using namespace std;

int pyramid[MAXN][MAXN];
int64_t dp[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int64_t i = 1, num = 1; i <= 2023; ++i){
        for(int j = 1; j <= i; ++j, ++num){
            pyramid[i][j] = num;
            dp[i][j] = num * num + dp[i - 1][j - 1];
        }
    }

    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        int64_t gauss = 0, num = 0;
        while(gauss < n) gauss += ++num;
        int idx = lower_bound(pyramid[num], pyramid[num] + num + 1, n) - pyramid[num];
        int64_t ans = 0;
        for(int i = num; 0 < i; --i) ans += dp[i][idx];
        cout << ans << '\n';
    }
}
