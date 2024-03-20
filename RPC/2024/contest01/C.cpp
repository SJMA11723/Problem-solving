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
    int n; cin >> n;
    int arr[n + 1]; arr[0] = 0;
    int rank[15] = {};
    for(int i = 1; i <= n; ++i){
        char c; cin >> c;
        if(c == 'A'){
            rank[1]++;
            arr[i] = 1;
        }
        else if(c == 'T'){
            rank[10]++;
            arr[i] = 10;
        }
        else if(c == 'J'){
            rank[11]++;
            arr[i] = 10;
        }
        else if(c == 'Q'){
            rank[12]++;
            arr[i] = 10;
        }
        else if(c == 'K'){
            rank[13]++;
            arr[i] = 10;
        } else {
            rank[c - '0']++;
            arr[i] = c - '0';
        }
    }

    int64_t dp[n + 1][16];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i){
        for(int s = 0; s <= 15; ++s){
            dp[i][s] = dp[i - 1][s];
            if(arr[i] <= s){
                dp[i][s] += dp[i - 1][s - arr[i]];
                //cout << i << ' ' << s << ' ' << arr[i] << ' ' << dp[i][s] << '\n';
            }
        }
    }
    cout << 2 * dp[n][15] << '\n';

    int64_t ans = 2 * dp[n][15];
    for(int i = 0; i < 15; ++i)
        ans += rank[i] * (rank[i] - 1);
    cout << ans - 2 * dp[n][15] << '\n';

    int64_t cnt = 0;
    int64_t prod = 1;
    for(int i = 1; i <= 14; ++i){
        if(rank[i] == 0){
            if(cnt >= 3) ans += prod * cnt;
            prod = 1;
            cnt = 0;
        } else prod *= rank[i], cnt++;
    }
    cout << ans << '\n';
}
