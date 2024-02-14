/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 50001

using namespace std;

int dp[MAXN];

int compute(int n, int rice[], int p){
    if(n <= 0) return abs(n);

    if(dp[n] != -1) return dp[n];

    dp[n] = INT_MAX;
    for(int i = 0; i < p; ++i) dp[n] = min(dp[n], compute(n - rice[i], rice, p));
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, p;
    cin >> k >> p;
    int rice[p];
    for(int i = 0; i < p; ++i) cin >> rice[i];

    fill(dp, dp + MAXN, -1);
    while(k--){
        int n; cin >> n;
        cout << compute(n, rice, p) << '\n';
    }
}
