/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t SG(int64_t n){
    return n * (n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        int64_t k; cin >> n  >> k;
        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            //cout << "M: " << mid << ' ' << SG(mid - 1) << '\n';
            if(SG(mid - 1) < k) l = mid + 1;
            else r = mid;
        }
        l--;
        string ans(n, 'a');
        k -= SG(l - 1);
        ans[n - 1 - l] = 'b';
        ans[n - k] = 'b';
        cout << ans << '\n';
    }
}
