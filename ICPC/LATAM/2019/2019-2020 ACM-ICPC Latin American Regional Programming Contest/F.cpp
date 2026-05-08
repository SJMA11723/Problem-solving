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
    int S, B; cin >> S >> B;

    B -= S;
    int dp[S + 1][B + 1];
    for(int s = 0; s <= S; ++s){
        for(int b = 0; b <= B; ++b){
            dp[s][b] = 0;
            if(!b){
                dp[s][b] = 1;
                continue;
            }

            if(s && s <= b) dp[s][b] += dp[s][b - s];
            if(dp[s][b] >= MOD) dp[s][b] -= MOD;
            
            if(1 <= s) dp[s][b] += 2 * dp[s - 1][b] % MOD;
            if(dp[s][b] >= MOD) dp[s][b] -= MOD;

            if(2 <= s) dp[s][b] += (MOD - dp[s - 2][b]) % MOD;
            if(dp[s][b] >= MOD) dp[s][b] -= MOD;
        }
    }

    cout << dp[S][B] << '\n';
}