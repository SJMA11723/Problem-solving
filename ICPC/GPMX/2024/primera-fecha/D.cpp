/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int inv2 = 500000004;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t ans = 0;
    for(int64_t M = 1; M <= n - 2; ++M){
        int64_t S = min(n - M, 2 * M);
        if(S < M) continue;

        int64_t triangles = (2 * M + 1) * (S - M) - S * (S + 1) / 2 + M * (M + 1) / 2;

        triangles += S / 2 - M / 2;
        ans += triangles / 2;
        ans %= MOD;
    }
    cout << ans << '\n';
}
