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

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    ll ans = 0;
    int cnt_row[n] = {}, cnt_col[m] = {};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            cnt_row[i] += x;
            cnt_col[j] += x;
        }
    }
    for(int i = 0; i < n; ++i) ans += (1ll << cnt_row[i]) + (1ll << (m - cnt_row[i]));
    for(int i = 0; i < m; ++i) ans += (1ll << cnt_col[i]) + (1ll << (n - cnt_col[i]));
    ans -= n * m + 2 * (n + m);
    cout << ans << '\n';
}