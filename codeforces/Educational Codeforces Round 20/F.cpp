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

const ll MOD = 1e9 + 7;

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
    int dp[MAXVAL + 1] = {};
    for(int &x : arr){
        cin >> x;
        for(int i = 1; i * i <= x; ++i){
            if(x % i) continue;
            dp[i]++;
            if(i * i != x) dp[x / i]++;
        }
    }

    for(int i = MAXVAL; 0 < i; --i){
        dp[i] = bin_exp(2, dp[i]) - 1;
        if(dp[i] < 0) dp[i] += MOD;
        for(int j = 2 * i; j <= MAXVAL; j += i){
            dp[i] -= dp[j];
            if(dp[i] < 0) dp[i] += MOD;
        }
    }
    cout << dp[1] << '\n';
}