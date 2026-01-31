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

struct weapon{
    int a, b, c;
};

bool comp(weapon A, weapon B){
    return A.a * B.b + A.b < B.a * A.b + B.b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, P; cin >> n >> P;
    weapon arr[n];
    for(weapon &w : arr) cin >> w.a >> w.b >> w.c;

    sort(arr, arr + n, comp);
    reverse(arr, arr + n);

    //for(weapon &w : arr) cout << w.a << w.b << w.c << '\n';

    int dp[n][P + 1], ans = 0;
    memset(dp, 0, sizeof(dp));
    for(int p = 0; p <= P; ++p){
        if(p - arr[0].b < 0) continue;
        dp[0][p] = arr[0].c;
        ans = max(ans, dp[0][p]);
    }

    for(int i = 1; i < n; ++i){
        for(int p = 0; p <= P; ++p){
            dp[i][p] = dp[i - 1][p];
            if(p - arr[i].b >= 0) dp[i][p] = max(dp[i][p], dp[i - 1][(p - arr[i].b) / arr[i].a] + arr[i].c);
            ans = max(ans, dp[i][p]);
        }
    }

    cout << ans << '\n';
    //cout << *max_element(dp[n - 1], dp[n - 1] + P + 1) << '\n';
}