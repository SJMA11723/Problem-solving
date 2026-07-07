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

const int MOD = 1e9 + 7;

#define MAXN 40000

bool is_palin(int n){
    int tmp = n, rev = 0;
    while(tmp > 0){
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi palin;
    for(int i = 1; i <= MAXN; ++i)
        if(is_palin(i)) palin.pb(i);
    
    int N = sz(palin);
    int dp[MAXN + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int c : palin){
        for(int j = c; j <= MAXN; ++j){
            dp[j] += dp[j - c];
            if(dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}