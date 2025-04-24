/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t binom(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    k = min(k, n - k);
    int64_t res = 1;
    for(int i = 0; i < k; ++i){
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int64_t d[5] = {1, 0, 1, 2, 9};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int64_t ans = 0;
    for(int i = 0; i <= k; ++i) ans += binom(n, i) * d[i];
    cout << ans << '\n';
}
