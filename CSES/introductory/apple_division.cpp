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
    int64_t sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    int64_t ans = sum;
    int lim = 1 << n;
    for(int mask = 1; mask < lim; ++mask){
        int tmp = mask;
        int64_t diff = -sum; /// x - (sum - x) = 2x - sum
        while(tmp){
            diff += 2ll * arr[__builtin_ffs(tmp) - 1];
            tmp ^= 1 << (__builtin_ffs(tmp) - 1);
        }
        ans = min(ans, abs(diff));
    }

    cout << ans << '\n';
}
