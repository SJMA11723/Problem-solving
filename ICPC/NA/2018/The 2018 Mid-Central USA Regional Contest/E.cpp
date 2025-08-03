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

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int maxi = max(b, d);
    ll dp[maxi + 1] = {};

    for(int i = maxi; 0 < i; --i){
        dp[i] = 1ll * (b / i - (a - 1) / i) * (d / i - (c - 1) / i);
        for(int j = 2 * i; j <= maxi; j += i) dp[i] -= dp[j];
    }
    cout << dp[1] << '\n';
}