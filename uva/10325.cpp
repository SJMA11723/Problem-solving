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
    int n, m;
    while(cin >> n){
        cin >> m;
        int arr[m];
        for(int &x : arr) cin >> x;

        int lim = 1 << m;
        int64_t cnt_multiples = 0;
        for(int mask = 1; mask < lim; ++mask){
            int64_t mlcm = 1;
            for(int i = 0; i < m; ++i)
            if(is_on(mask, i)){
                mlcm = mlcm / __gcd(mlcm, (int64_t)arr[i]) * arr[i];
                if(mlcm > n) break;
            }

            cnt_multiples += n / mlcm * (__builtin_parity(mask) ? 1 : -1);
        }
        cout << n - cnt_multiples << '\n';
    }
}
