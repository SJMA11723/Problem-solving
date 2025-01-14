/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 6;

int bin_exp(int a, int64_t b, const int M){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2, M);
    if(b % 2) return 1ll * tmp * tmp % M * a % M;
    return 1ll * tmp * tmp % M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt_div, sum_div, prod_div;
    cnt_div = sum_div = prod_div = 1;
    pair<int, int> arr[n];
    int64_t sum_exp = 0;
    int L[n], R[n + 1];
    R[n] = 0;
    for(int i = 0; i < n; ++i){
        int p, x; cin >> p >> x;
        cnt_div = 1ll * cnt_div * (x + 1) % MOD;
        sum_div = 1ll * sum_div * (bin_exp(p, x + 1, MOD) - 1 + MOD) % MOD * bin_exp(p - 1, MOD - 2, MOD) % MOD;
        arr[i] = {p, x};

        if(i) L[i] = 1ll * (x + 1) * L[i - 1] % MOD2;
        else L[i] = x + 1;
    }

    R[n - 1] = arr[n - 1].second + 1;
    for(int i = n - 2; 0 <= i; --i) R[i] = 1ll * (arr[i].second + 1) * R[i + 1] % MOD2;

    prod_div = bin_exp(arr[0].first, 1ll * arr[0].second * (arr[0].second + 1) / 2 % MOD2 * R[1] % MOD2, MOD);
    for(int i = 1; i + 1 < n; ++i){
        int p, x; tie(p, x) = arr[i];
        prod_div = 1ll * prod_div * bin_exp(p, 1ll * x * (x + 1) / 2 % MOD2 * L[i - 1] % MOD2 * R[i + 1] % MOD2, MOD) % MOD;
    }
    prod_div = 1ll * prod_div * bin_exp(arr[n - 1].first, 1ll * arr[n - 1].second * (arr[n - 1].second + 1) / 2 % MOD2 * (n == 1 ? 1 : L[n - 2]) % MOD2, MOD) % MOD;

    cout << cnt_div << ' ' << sum_div << ' ' << prod_div << '\n';
}
