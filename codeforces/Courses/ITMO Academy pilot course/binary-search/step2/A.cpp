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
    int64_t n, h, w; cin >> w >> h >> n;
    int64_t l = 0, r = LLONG_MAX;
    while(l < r){
        __int128_t mid = l + (r - l) / 2;
        if(mid / w * (mid / h) >= n) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
