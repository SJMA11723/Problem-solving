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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXE 60

const int MOD = 1e9 + 7;

ll bin_exp(ll a, int b, const ll MAX){
    if(!b) return 1;
    ll tmp = bin_exp(a, b / 2, MAX);
    if(tmp > MAX / tmp) return LLONG_MAX;
    tmp *= tmp;
    if(b & 1) return tmp > MAX / a ? LLONG_MAX : tmp * a;
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll dp[MAXE + 1];
        for(int i = MAXE; 0 < i; --i){
            /*ll l = 2, r = n + 1;
            while(l < r){
                ll mid = l + (r - l) / 2;
                ll powmid = 1;
                for(int j = 0; j < i; ++j){
                    if(powmid > n / mid){
                        powmid = LLONG_MAX;
                        break;
                    }
                    powmid *= mid;
                }

                if(powmid > n) r = mid;
                else l = mid + 1;
            }
            dp[i] = r - 2;*/
            dp[i] = ceill(powl(n, 1.0 / i)) - 1;
            while(bin_exp(dp[i], i, n) <= n) dp[i]++;
            dp[i] -= 2;
            for(int j = 2 * i; j <= MAXE; j += i)
                dp[i] -= dp[j];
        }
        cout << dp[1] << '\n';
    }
}