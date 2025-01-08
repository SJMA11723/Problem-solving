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
    int64_t n; cin >> n;
    int64_t ans = 0;
    for(int64_t p = 2; p * p <= n; ++p){
        if(n % p) continue;
        int64_t cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        ans += (sqrt(8 * cnt + 1) - 1) / 2;
    }
    if(n > 1) ans += 1;
    cout << ans << '\n';
}
