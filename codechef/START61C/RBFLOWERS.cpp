#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int arr2[n];
        int dp[n][20001];

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        for(int i = 0; i < n; ++i){
            cin >> arr2[i];
        }

        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= 20000; ++j)
                dp[i][j] = -1;

        /**
            dp states:
            0 <= i < n (index)
            f(i, sumRed) = sumBlue

            answer = max(f(n - 1, 0), f(n - 1, 1), ..., f(n - 1, MAXSUMRED))
        */
        dp[0][0] = arr2[0];
        dp[0][ arr[0] ] = 0;

        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= 20000; ++j){
                if(dp[i - 1][j] == -1) continue;

                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr2[i]);
                dp[i][j + arr[i]] = max(dp[i][j + arr[i]], dp[i - 1][j]);
            }
        }

        int ans = 0;

        for(int i = 0; i <= 20000; ++i)
            ans = max(ans, min(i, dp[n - 1][i]));

        cout << ans << '\n';
    }
}
