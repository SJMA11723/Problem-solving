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
#define MAXN 100000

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dp[MAXN + 1], cnt[MAXN + 1];
    /// dp[x]: # of a_j < i s.t. gcd(a_j, a_i) = x
    vi divs[MAXN + 1];
    vi primes[MAXN + 1];
    for(int i = 1; i <= MAXN; ++i){
        for(int j = i; j <= MAXN; j += i){
            divs[j].pb(i);
        }

        if(i == 1 || primes[i].size()) continue;

        for(int j = i; j <= MAXN; j += i){
            primes[j].pb(i);
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + n);
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        ll ans = 0;
        for(int i = 0; i < n; ++i){
            for(int d : divs[arr[i]]) dp[d] = cnt[d];

            for(int p : primes[arr[i]]){{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
                for(int d : divs[arr[i]]){
                    if(d % p) continue;
                    dp[d / p] -= dp[d];
                }
            }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

            for(int d : divs[arr[i]]){
                ans += 1ll * d * dp[d] * (n - 1 - i);
                dp[d] = 0;
                cnt[d]++;
            }
        }

        cout << ans << '\n';
    }
}