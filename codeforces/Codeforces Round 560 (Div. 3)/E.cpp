/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t a[n];
    int b[n];
    for(int64_t &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int i = 1; i <= n; ++i) a[i - 1] *= 1ll * i * (n - i + 1);

    sort(a, a + n);
    sort(b, b + n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += a[i] % MOD * b[n - 1 - i] % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
