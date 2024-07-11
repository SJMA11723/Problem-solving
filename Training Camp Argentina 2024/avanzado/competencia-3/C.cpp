/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

/**
    0: NN|BB
    1: NB|BN
    2: BB|NN
    3: BN|NB
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h; cin >> w >> h;
    int ans = 1;
    for(int i = 0; i < h + w; ++i) ans = ans * 2 % MOD;
    cout << ans << '\n';
}
