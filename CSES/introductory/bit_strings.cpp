/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        ans <<= 1;
        if(ans > MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
