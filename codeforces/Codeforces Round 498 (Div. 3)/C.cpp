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

    multiset<int64_t> sums;
    int64_t sum_r = 0;
    for(int i = n - 1; 0 <= i; --i){
        sum_r += arr[i];
        sums.insert(sum_r);
    }

    int64_t ans = 0;
    int64_t sum_l = 0;
    for(int i = 0; i < n; ++i){
        sums.erase(sums.find(sum_r));

        sum_l += arr[i];
        sum_r -= arr[i];

        auto it = sums.find(sum_l);
        if(it != sums.end()) ans = sum_l;
    }
    cout << ans << '\n';
}
