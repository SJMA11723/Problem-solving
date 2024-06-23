/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t sum(int n, int64_t arr[], int64_t w){
    int64_t res = 0;
    for(int i = 0; i < n; ++i) res += (1ll*arr[i] + 2 * w) * (1ll*arr[i] + 2 * w);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t n, c; cin >> n >> c;
        int64_t arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int64_t l = 1, r = sqrt(c / n) + 1;
        while(l < r){
            int64_t mid = (l + r) / 2;
            if(sum(n, arr, mid) < c) l = mid + 1;
            else r = mid;
        }
        cout << l << '\n';
    }
}
