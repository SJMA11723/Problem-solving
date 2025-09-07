#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    ll a; cin >> a;
    ll b = 1ll * n * m - a;


    int ans = 3;
    if(a % n == 0 || a % m == 0) ans = min(ans, 1);
    if(b % n == 0 || b % m == 0) ans = min(ans, 1);

    for(int i = 1; 1ll * i * i <= a; ++i){
        if(a % i) continue;

        ll d1 = i, d2 = a / i;
        if((d1 < n && d2 < m) || (d2 < n && d1 < m)){
            ans = min(ans, 2);
            break;
        }
    }

    for(int i = 1; 1ll * i * i <= b; ++i){
        if(b % i) continue;

        ll d1 = i, d2 = b / i;
        if((d1 < n && d2 < m) || (d2 < n && d1 < m)){
            ans = min(ans, 2);
            break;
        }
    }

    cout << ans << '\n';
}