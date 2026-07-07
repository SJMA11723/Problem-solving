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
    int n; cin >> n;
    vi ans = {1};
    int cnt = 0, sq = -1;
    for(int i = 2; i < n; ++i)
    if(gcd(i, n) == 1){
        if(1ll * i * i % n != 1 || cnt > 1) ans.pb(i);
        else {
            if(cnt == 0) sq = i;
            else {
                ans.pb(sq);
                ans.pb(i);
            }
            cnt++;
        }
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    for(int i = 0; i < sz(ans); ++i) cout << ans[i] << " \n"[i + 1 == sz(ans)];
}
