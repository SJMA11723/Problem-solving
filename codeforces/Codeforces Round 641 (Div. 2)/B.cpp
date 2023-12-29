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
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        int dp[n + 1] = {};
        for(int i = n; 0 < i; --i){
            dp[i] = 1;
            for(int j = i; j <= n; j += i){
                if(arr[i - 1] < arr[j - 1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp, dp + n + 1) << '\n';
    }
}
