/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t S(int64_t x){
    return x * (x + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int l = k, r = k + n - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            int64_t diff = abs(2 * S(mid) - S(k - 1) - S(k + n - 1));
            int64_t diff_next = abs(2 * S(mid + 1) - S(k - 1) - S(k + n - 1));
            if(diff >= diff_next) l = mid + 1;
            else r = mid;
        }
        cout << abs(2 * S(l) - S(k - 1) - S(k + n - 1)) << '\n';
    }
}
