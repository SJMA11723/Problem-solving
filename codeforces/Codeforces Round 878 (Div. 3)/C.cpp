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
        int n, k, q; cin >> n >> k >> q;
        int last = -1;
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x > q){
                int L = i - last - 1;
                if(L >= k) ans += ( 1ll * (L - 2 * k + 2) * (L + 1) + 1ll * k * (k - 1) ) / 2;
                last = i;
            }
        }
        int L = n - last - 1;
        if(L >= k) ans += ( 1ll * (L - 2 * k + 2) * (L + 1) + 1ll * k * (k - 1) ) / 2;
        cout << ans << '\n';
    }
}