/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[51][51];

long long combi(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    if(n == k || k == 0) return 1;
    if(dp[n][k]) return dp[n][k];
    return dp[n][k] = combi(n - 1, k - 1) + combi(n - 1, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n], cub[51] = {};
        for(int i = 0; i < n; ++i) cin >> arr[i], cub[arr[i]]++;
        sort(arr, arr + n);

        int mset[51] = {};
        int sum = 0;
        for(int i = 0; i < k; ++i) sum += arr[i], mset[arr[i]]++;

        long long ans = 1;
        for(int i = 1; i < 51; ++i) ans *= combi(cub[i],  mset[i]);
        cout << ans << '\n';
    }
}
