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
    for(int i = 0; i < n; ++i) last[arr[i]] = i;

    int prv[n];
    int dp[n] = {};
    int diff[n] = {};
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        prv[i] = i;
        diff[i] = 0;

        for(int k = 0; arr[i] - (1ll << k) >= arr[0]; ++k){
            if(!last.count(arr[i] - (1ll << k))) continue;
            int pos = last[arr[i] - (1ll << k)];

            if((!diff[pos] || diff[pos] == (1ll << k)) && dp[pos] + 1 > dp[i] && dp[pos] < 3){
                dp[i] = dp[pos] + 1;
                prv[i] = pos;
                diff[i] = diff[pos] + (1ll << k);
            }
        }
    }

    int idx_ans = max_element(dp, dp + n) - dp;
    cout << dp[idx_ans] << '\n';
    while(prv[idx_ans] != idx_ans){
        cout << arr[idx_ans] << ' ';
        idx_ans = prv[idx_ans];
    }
    cout << arr[idx_ans] << '\n';
}
