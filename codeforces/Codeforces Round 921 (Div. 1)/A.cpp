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
        int n, k, m;
        cin >> n >> k >> m;
        string s; cin >> s;

        int dp[n][k];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; ++i){
            if(s[i] >= 'a' + k) continue;

            if(!dp[0][s[i] - 'a']) dp[0][s[i] - 'a'] = i + 1;
            for(int j = 1; j < n; ++j){
                bool ok = true;
                for(int c = 0; c < k; ++c) ok = ok && dp[j - 1][c] && dp[j - 1][c] < i + 1;

                if(ok && !dp[j][s[i] - 'a']) dp[j][s[i] - 'a'] = i + 1;
            }
        }

        if(*min_element(dp[n - 1], dp[n - 1] + k)) cout << "YES\n";
        else {
            cout << "NO\n";

            for(int i = 0; i < n; ++i){
                int mini = min_element(dp[i], dp[i] + k) - dp[i];
                int maxi = max_element(dp[i], dp[i] + k) - dp[i];
                if(!dp[i][mini]){
                     cout << string(n - i, 'a' + mini);
                     break;
                } else cout << char('a' + maxi);
            }
            cout << '\n';
        }
    }
}
