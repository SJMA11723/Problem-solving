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
    long double n, k, s, d;
    cin >> n >> k >> d >> s;
    long double prom = (n * d - k * s) / (n - k);
    if(prom < 0 || 100 < prom) cout << "impossible\n";
    else cout << fixed << setprecision(20) << prom << '\n';
}
