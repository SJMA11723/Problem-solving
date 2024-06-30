/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t pos(int64_t n){
    int64_t res = 0;
    int64_t pot = 1;
    for(int i = 0; pot <= n; ++i){
        res += pot / 10 * 9 * i;
        pot *= 10;
    } pot /= 10;
    res += (n - pot) * ((int)log10(pot) + 1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        int64_t k; cin >> k;
        int64_t l = 0, r = 1e18;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            if(pos(mid) >= k) r = mid;
            else l = mid + 1;
        }
        l--;
        k -= pos(l);
        string num = to_string(l);
        cout << num[k - 1] << '\n';
    }
}
