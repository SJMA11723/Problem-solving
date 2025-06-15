#/**
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

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        int arr[n];
        for(int &x : arr) cin >> x;
        pair<int, ll> dp[n];
        dp[1] = {1, -max(0, max(arr[0], arr[2]) - arr[1] + 1 )};

        for(int i = 2; i < n; ++i){
            pair<int, ll> cur = dp[i - 2];
            if(i + 1 < n){
                cur.fi++;
                cur.se -= max(0, max(arr[i - 1], arr[i + 1]) - arr[i] + 1);
            }
            dp[i] = max(dp[i - 1], cur);
        }
        
        cout << -dp[n - 1].se << '\n';
    }
}
