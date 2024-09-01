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
        int l, r; cin >> l >> r;

        int lo = 0, hi = r - l + 5;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(1ll * mid * (mid + 1) / 2 <= r - l) lo = mid + 1;
            else hi = mid;
        }
        cout << lo << '\n';
    }
}
