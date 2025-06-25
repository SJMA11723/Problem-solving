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
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0, sum = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x == 1) sum++, cnt++;
            else if(x == 2) sum <<= 1;
            else {
                ans += (sum - cnt + MOD) % MOD;
                if(ans >= MOD) ans -= MOD;
            }
            if(sum >= MOD) sum -= MOD;
        }
        cout << ans << '\n';
    }
}
