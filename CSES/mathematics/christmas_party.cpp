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
    if(n == 1){
        cout << "0\n";
        return 0;
    } else if(n == 2){
        cout << "1\n";
        return 0;
    }
    int prv2 = 0, prv1 = 1;
    for(int i = 3; i <= n; ++i){
        int cur = 1ll * (i - 1) * (prv1 + prv2) % MOD;
        prv2 = prv1;
        prv1 = cur;
    }
    cout << prv1 << '\n';
}
