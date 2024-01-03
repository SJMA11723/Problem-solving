/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(i, n) ((n) & (1ll << i))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[4], d;
    for(int i = 0; i < 4; ++i) cin >> arr[i];
    cin >> d;

    int ans = 0;
    int lim = 1 << 4;
    for(int mask = 1; mask < lim; ++mask){
        int lwcm = 1;
        for(int i = 0; i < 4; ++i)
            if(is_on(i, mask)) lwcm = lcm(lwcm, arr[i]);
        if(__builtin_popcount(mask) % 2) ans += d / lwcm;
        else ans -= d / lwcm;
    }
    cout << ans << '\n';
}
