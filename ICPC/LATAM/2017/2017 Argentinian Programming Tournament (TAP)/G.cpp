#include <bits/stdc++.h>
#define lsb(n) ((n) & -(n))

#define MAXN 100
#define MAXP 1000

using namespace std;

const int MOD = 1e9 + 7;

int fact[MAXN + 1], inv_fact[MAXN + 1];

int binom(int n, int k){
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 875453797;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int n, m, p1, p2;
    cin >> n >> m >> p1 >> p2;

    int dp[n + 1][MAXP + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= MAXP; ++j){
            for(int k = 1; k <= min(j, m); ++k){
                dp[i][j] += dp[i - 1][j - k];
                if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
    }


    int ans = 0;
    for(int k = 0; k < n; ++k){
        int N = n - k;
        int sumN = 0;
        for(int x = 1; x < N; ++x){
            int C1 = dp[x][p1];
            int C2 = dp[N - x][p2];
            sumN += 1ll * C1 * C2 % MOD * binom(N, x) % MOD;
            if(sumN >= MOD) ans -= MOD;
        }
        sumN = 1ll * sumN * binom(n, k) % MOD;
        ans += sumN;
        if(ans >= MOD) ans -= MOD;
    }
    /// C1 * C2 * binom(n - k, x) * binom(n, k);

    cout << ans << '\n';
}
