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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        pair<int64_t, int> dp[n][2];
        dp[0][0] = {n, 1};
        dp[0][1] = {1e15, -1};
        for(int i = 1; i < n; ++i){
            if(s[i] == '('){
                dp[i][1] = {1e15, -1};

                if(dp[i - 1][0].first < dp[i - 1][1].first) dp[i][0] = dp[i - 1][0];
                else dp[i][0] = dp[i - 1][1];

                dp[i][0].second++;
                dp[i][0].first += n - i;
            } else if(s[i] == ')'){
                dp[i][0] = {1e15, -1};

                if(dp[i - 1][0].first < dp[i - 1][1].first) dp[i][1] = dp[i - 1][0];
                else dp[i][1] = dp[i - 1][1];

                dp[i][1].second--;
                dp[i][1].first -= n - i;
                if(dp[i][1].second < 0) dp[i][1].first = 1e15;
            } else {
                if(dp[i - 1][0].first < dp[i - 1][1].first) dp[i][0] = dp[i - 1][0];
                else dp[i][0] = dp[i - 1][1];

                dp[i][0].second++;
                dp[i][0].first += n - i;


                if(dp[i - 1][0].first < dp[i - 1][1].first) dp[i][1] = dp[i - 1][0];
                else dp[i][1] = dp[i - 1][1];

                dp[i][1].second--;
                dp[i][1].first -= n - i;
                if(dp[i][1].second < 0) dp[i][1].first = 1e15;
            }
        }

        cout << dp[n - 1][1].first << '\n';
    }
}
