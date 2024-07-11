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
    vector<int> pos[n + 1];
    for(int i = 1; i <= 2 * n; ++i){
        int a; cin >> a;
        pos[a].push_back(i);
    }

    pos[0] = {1, 1};
    int64_t dp[n + 1][2];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; ++i){
        dp[i][0] = min(dp[i - 1][0] + abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]),
                       dp[i - 1][1] + abs(pos[i][0] - pos[i - 1][1]) + abs(pos[i][1] - pos[i - 1][0]));

        dp[i][1] = min(dp[i - 1][0] + abs(pos[i][1] - pos[i - 1][0]) + abs(pos[i][0] - pos[i - 1][1]),
                       dp[i - 1][1] + abs(pos[i][1] - pos[i - 1][1]) + abs(pos[i][0] - pos[i - 1][0]));
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}
