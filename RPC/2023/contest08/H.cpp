/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 5005

using namespace std;

typedef long long ll;

ll cost[MAXN][3], dp[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, L;
    cin >> L >> T;
    for(int i = 1; i <= T; ++i) cin >> cost[i][1] >> cost[i][2] >> cost[i][3];

    fill(dp[1], dp[1] + MAXN, (ll)INT_MAX * 100);
    dp[1][0] = 0;
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];
    dp[1][3] = cost[1][3];

    for(int i = 2; i <= T; ++i){
        for(int j = 0; j <= L; ++j){
            ll a = dp[i - 1][j], b, c, d;
            b = c = d = (ll)INT_MAX * 100;
            if(1 <= j) b = cost[i][1] + dp[i - 1][j - 1];
            if(2 <= j) c = cost[i][2] + dp[i - 1][j - 2];
            if(3 <= j) d = cost[i][3] + dp[i - 1][j - 3];
            dp[i][j] = min({a, b, c, d});
        }
    }

    cout << dp[T][L] << '\n';
}
