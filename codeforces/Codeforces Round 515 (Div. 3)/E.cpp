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
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int ans = 0, pow2 = 1, sumpow = 0;
    for(int i = 0; i < m; ++i){
        if(i < n && a[i] == '1'){
            sumpow += pow2;
            if(sumpow > MOD) sumpow -= MOD;
        }

        if(b[i] == '1'){
            ans += sumpow;
            if(ans >= MOD) ans -= MOD;
        }

        pow2 += pow2;
        if(pow2 >= MOD) pow2 -= MOD;
    }
    cout << ans << '\n';
}
