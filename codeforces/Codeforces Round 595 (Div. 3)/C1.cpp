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
    int pow3[11];
    pow3[0] = 1;
    for(int i = 1; i < 11; ++i) pow3[i] = 3 * pow3[i - 1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int lim = 1 << 10;
        int ans = INT_MAX;
        for(int mask = 1; mask < lim; ++mask){
            int num = 0;
            for(int i = 0; i < 10; ++i)
                if(is_on(mask, i)) num += pow3[i];
            if(num >= n) ans = min(ans, num);
        }

        cout << ans << '\n';
    }
}
