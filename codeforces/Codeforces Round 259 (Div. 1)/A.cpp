/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

long double bin_exp(long double a, int64_t b){
    if(!b) return 1;
    long double tmp = bin_exp(a, b / 2);
    if(b % 2) return tmp * tmp * a;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> m >> n;
    long double ans = 0;
    for(int i = 1; i <= m; ++i) ans += i * (bin_exp(1.0 * i / m, n) - bin_exp(1.0 * (i - 1) / m, n));
    cout << fixed << setprecision(6) << ans << '\n';
}
