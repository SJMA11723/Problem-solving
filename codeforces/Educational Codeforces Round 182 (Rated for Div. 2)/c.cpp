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

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; ++i){
            if(a[i - 1] <= a[i] && b[i - 1] <= b[i]){
                dp[i][0] += dp[i - 1][0]; // no swap cur y prv
                dp[i][1] += dp[i - 1][1]; // swap cur y prv
            }

            if(b[i - 1] <= a[i] && a[i - 1] <= b[i]){
                dp[i][0] += dp[i - 1][1]; // swap prv
                dp[i][1] += dp[i - 1][0]; // swap cur
            }

            if(dp[i][0] >= MOD) dp[i][0] -= MOD;
            if(dp[i][1] >= MOD) dp[i][1] -= MOD;
        }
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << '\n';
    }
}
