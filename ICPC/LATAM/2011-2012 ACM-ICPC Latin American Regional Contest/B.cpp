#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n){
        vector<int> mat[n + 1];
        vector<int> dp[n + 1];

        for(int i = 0; i <= n; ++i){
            mat[i].resize(i + 2);
            for(int j = 1; j <= i; ++j) cin >> mat[i][j];
            dp[i].resize(n - i + 2);
        }

        for(int j = 1; j <= n; ++j){
            int sum = 0;
            for(int k = 0; k <= n - j + 1; ++k){
                sum += mat[k + j - 1][j];
                dp[k][j] = dp[k][j - 1] + sum;
            }

            for(int k = n - j; 0 <= k; --k)
                dp[k][j] = max(dp[k][j], dp[k + 1][j]);
        }

        cout << dp[0][n] << '\n';
        cin >> n;
    }
}
