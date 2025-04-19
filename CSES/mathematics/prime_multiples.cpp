/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int k; cin >> k;
    int64_t arr[k];
    for(int64_t &x : arr) cin >> x;

    int64_t cnt_multiples = 0;
    int lim = 1 << k;
    for(int mask = 1; mask < lim; ++mask){
        __int128_t mlcm = 1;
        for(int i = 0; i < k; ++i)
        if(is_on(mask, i)){
            mlcm *= arr[i];
            if(mlcm > n) break;
        }

        cnt_multiples += n / mlcm * (__builtin_parity(mask) ? 1 : -1);
    }
    cout << cnt_multiples << '\n';
}
