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
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;
    sort(arr, arr + n);

    map<int, int> last;
    int dp[n] = {}, prv[n];
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        prv[i] = i;
        for(int k = 0; k <= 30; ++k){
            if(last.count(arr[i] - (1 << k))){
                int j = last[arr[i] - (1 << k)];
                if(dp[j] < 3 && dp[i] < dp[j] + 1 && (dp[j] == 1 || arr[j] - arr[prv[j]] == (1 << k))){
                    dp[i] = dp[j] + 1;
                    prv[i] = j;
                }
            }
        }
        last[arr[i]] = i;
    }

    int idx_ans = max_element(dp, dp + n) - dp;
    cout << dp[idx_ans] << '\n';
    while(prv[idx_ans] != idx_ans){
        cout << arr[idx_ans] << ' ';
        idx_ans = prv[idx_ans];
    }
    cout << arr[idx_ans] << '\n';
}
