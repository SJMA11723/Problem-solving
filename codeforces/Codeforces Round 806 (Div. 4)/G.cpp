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
        int n;
        long long k;
        cin >> n >> k;
        long long arr[n], dp[n][32] = {{}};
        for(int i = 0; i < n; ++i){
             cin >> arr[i];
        }

        for(int j = 0; j < 31; ++j)
            dp[n - 1][j] = max(arr[n - 1] >> (j + 1), (arr[n - 1] >> j) - k);

        for(int i = n - 2; 0 <= i; --i){
            for(int j = 0; j < 31; ++j){
                dp[i][j] = max( (arr[i] >> j) - k + dp[i + 1][j], (arr[i] >> (j + 1)) + dp[i + 1][j + 1] );
            }
        }
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
}
