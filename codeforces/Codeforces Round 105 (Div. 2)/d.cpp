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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, b; cin >> w >> b;
    long double dp[2][b + 1];
    memset(dp, 0, sizeof(dp));
    bool i2 = 1;
    for(int i = 1; i <= w; ++i, i2 = !i2){
        dp[i2][0] = 1;
        if(0 < b) dp[i2][1] = 1.0L * i / (i + 1);
        if(1 < b) dp[i2][2] = 1.0L * i / (i + 2) + (i > 1) * (2.0L / (i + 2)) * (1.0L / (i + 1));
        for(int j = 3; j <= b; ++j){
            dp[i2][j] = 1.0L * i / (i + j);
            dp[i2][j] += (1.0L * j / (i + j)) * (1.0L * (j - 1) / (i + j - 1)) * (1.0L * i / (i + j - 2)) * dp[!i2][j - 2];
            dp[i2][j] += (1.0L * j / (i + j)) * (1.0L * (j - 1) / (i + j - 1)) * (1.0L * (j - 2) / (i + j - 2)) * dp[i2][j - 3];
        }
    }
    cout << fixed << setprecision(10) << dp[w & 1][b] << '\n';
}