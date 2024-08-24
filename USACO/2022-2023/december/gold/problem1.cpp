/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct cows{
    int P = 0, C = 0, X = 0;
    bool operator<(const cows &b){
        return X > b.X;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    cows arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i].P >> arr[i].C >> arr[i].X;
    sort(arr + 1, arr + n + 1);

    int dp[2][2][max(a, b) + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i){

        for(int c = 0; c <= a; ++c){
            dp[i % 2][1][c] = dp[(i^1) % 2][1][c];
            if(arr[i].C <= c){
                dp[i % 2][1][c] = max(dp[i % 2][1][c], arr[i].P + dp[(i^1) % 2][1][c - arr[i].C]);
            }
        }

        for(int h = 0; h <= b; ++h){
            dp[i % 2][0][h] = max(dp[(i^1) % 2][0][h], dp[i % 2][1][a]);
            if(arr[i].C * arr[i].X <= h){
                dp[i % 2][0][h] = max(dp[i % 2][0][h], arr[i].P + dp[(i^1) % 2][0][h - arr[i].C * arr[i].X]);
            } else if(a >= arr[i].C - h / arr[i].X){
                dp[i % 2][0][h] = max(dp[i % 2][0][h], arr[i].P + dp[(i^1) % 2][1][a - (arr[i].C - h / arr[i].X)]);
            }
        }
    }

    cout << dp[n % 2][0][b] << '\n';
}
