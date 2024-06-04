#include<bits/stdc++.h>
#define MAXN 100'000

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t bin_exp(int64_t A, int64_t n){
    if(!n) return 1;

    int64_t tmp = bin_exp(A, n / 2);

    if(n % 2) return tmp * tmp % MOD * A % MOD;
    return tmp * tmp % MOD;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t fact[2 * MAXN + 1];
    fact[0] = 1;
    for(int64_t i = 1; i <= 2 * MAXN; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    int t; cin >> t;
    while(t--){
        int64_t N; cin >> N;
        cout << fact[2 * N - 1] * bin_exp(fact[N], MOD - 2) % MOD * bin_exp(fact[N - 1], MOD - 2) % MOD << '\n';
    }

    return 0;
}
