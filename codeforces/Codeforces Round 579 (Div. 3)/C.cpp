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
    int n; cin >> n;
    int64_t g = 0;
    for(int i = 0; i < n; ++i){
        int64_t x; cin >> x;
        g = gcd(g, x);
    }

    int ans = 0;
    for(int64_t i = 1; i * i <= g; ++i){
        if(g % i) continue;
        ans++;
        if(i * i != g) ans++;
    }
    cout << ans << '\n';
}
