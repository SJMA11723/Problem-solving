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
    int q; cin >> q;
    while(q--){
        int64_t n, m; cin >> n >> m;
        int64_t max_mult = n / m;
        m %= 10;
        int64_t ans = 0;
        for(int i = 1; i <= min(9ll, n); ++i){
            if(i <= max_mult % 10) ans += (max_mult + 9) / 10 * (i * m % 10);
            else ans += max_mult / 10 * (i * m % 10);
        }
        cout << ans << '\n';
    }
}
