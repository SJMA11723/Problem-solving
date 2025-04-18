/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXB 10000000000
#define MAXN 2000000

using namespace std;

const int MOD = 1e8 + 7;

int fact[MAXN + 1], inv_fact[MAXN + 1];
vector<int64_t> perfect_powers;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i <= 100000; ++i){
        int64_t powi = 1ll * i * i;
        while(powi <= MAXB){
            perfect_powers.push_back(powi);
            powi *= i;
        }
    }
    sort(perfect_powers.begin(), perfect_powers.end());
    /// pueden haber repetidos!!
    perfect_powers.resize(unique(perfect_powers.begin(), perfect_powers.end()) - perfect_powers.begin());

    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 83248412;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int64_t a, b; cin >> a >> b;
        int n = upper_bound(perfect_powers.begin(), perfect_powers.end(), b) - lower_bound(perfect_powers.begin(), perfect_powers.end(), a);
        cout << "Case " << tt << ": " << (n ? 1ll * fact[2 * n] * inv_fact[n + 1] % MOD * inv_fact[n] % MOD : 0) << '\n';
    }
}
