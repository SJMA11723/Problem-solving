/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool subarray(int64_t arr[], int l, int r){
    if(l == r) return false;

    bool ans_l = subarray(arr, l, (l + r) / 2);
    bool ans_r = subarray(arr, (l + r) / 2 + 1, r);

    if(ans_l || ans_r) return true;

    bool ans = false;
    int64_t sum = 0;
    set<int64_t> sums;
    for(int i = (l + r) / 2 + 1; i <= r; ++i){
        sum += i % 2 ? -arr[i] : arr[i];
        sums.insert(sum);
        if(sum == 0){
            ans = true;
            break;
        }
    }

    if(ans) return true;

    sum = 0;
    for(int i = (l + r) / 2; l <= i; --i){
        sum += i % 2 ? -arr[i] : arr[i];
        if(sum == 0 || sums.count(-sum)){
            ans = true;
            break;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int64_t arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << (subarray(arr, 0, n - 1) ? "YES\n" : "NO\n");
    }
}
