/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXVAL 1000000

const ll MOD = 998244353;
int cnt[MAXVAL + 1], dp[MAXVAL + 1], sumsq[MAXVAL + 1];

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr){
        cin >> x;
        cnt[x]++;
    }

    for(int i = MAXVAL; 0 < i; --i){
        for(int j = i; j <= MAXVAL; j += i){
            dp[i] += 1ll * j * cnt[j] % MOD;
            sumsq[i] += 1ll * j * j * cnt[j] % MOD;
            if(dp[i] >= MOD) dp[i] -= MOD;
            if(sumsq[i] >= MOD) sumsq[i] -= MOD;
        }
        dp[i] = 1ll * (1ll * dp[i] * dp[i] % MOD - sumsq[i] + MOD) * bin_exp(2, MOD - 2) % MOD;

        for(int j = 2 * i; j <= MAXVAL; j += i){
            dp[i] -= dp[j];
            if(dp[i] < 0) dp[i] += MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i <= MAXVAL; ++i){
        ans += 1ll * dp[i] * bin_exp(i, MOD - 2) % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}