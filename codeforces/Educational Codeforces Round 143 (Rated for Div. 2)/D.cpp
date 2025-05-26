/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 998244353;

vector<int> fact;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

int binom(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    return 1ll * fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    fact.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int ans = 1;
    for(int i = 0; i < n; i += 3){
        int a, b, c; cin >> a >> b >> c;
        int mini = min({a, b, c});
        int cnt_mini = 0;
        if(mini == a) cnt_mini++;
        if(mini == b) cnt_mini++;
        if(mini == c) cnt_mini++;
        ans = 1ll * ans * cnt_mini % MOD;
    }
    ans = 1ll * ans * binom(n / 3, n / 6) % MOD;
    cout << ans << '\n';
}
