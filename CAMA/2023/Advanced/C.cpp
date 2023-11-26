/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 201

using namespace std;

int dp[MAXN][MAXN];
bool processed[MAXN][MAXN];
int arr[MAXN];

int compute(int n, int x){
    if(!n) return x ? INT_MAX : 0;
    if(!x) return 0;

    if(processed[n][x]) return dp[n][x];
    processed[n][x] = true;

    dp[n][x] = compute(n - 1, x);
    for(int i = 0; i <= x; ++i){
        if(i + arr[n - 1] > x) continue;
        dp[n][x] = min(dp[n][x],  max(i, compute(n - 1, x - i - arr[n - 1])) );
    }

    return dp[n][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        for(int i = 0; i < MAXN; ++i) for(int j = 0; j < MAXN; ++j) dp[i][j] = INT_MAX;
        memset(processed, 0, sizeof(processed));
        cout << compute(n, x) << '\n';
    }
}
