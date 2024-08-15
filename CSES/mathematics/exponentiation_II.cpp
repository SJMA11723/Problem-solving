/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int bin_exp(int a, int b, const int MOD){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2, MOD);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--){
        int a, b, c; cin >> a >> b >> c;
        cout << bin_exp(a, bin_exp(b, c, 1e9 + 6), 1e9 + 7) << '\n';
    }
}
