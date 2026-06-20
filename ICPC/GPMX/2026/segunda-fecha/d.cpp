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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        ll x1, y1, r1;
        cin >> x1 >> y1 >> r1;

        ll x2, y2, r2;
        cin >> x2 >> y2 >> r2;

        ll k; cin >> k;

        if(k <= 2 * max(r1, r2)){
            cout << "YES\n";
            continue;
        }

        ll dx = x1 - x2;
        ll dy = y1 - y2;
        ll d = dx * dx + dy * dy;

        if(d <= max(r1, r2) * max(r1, r2) &&
            k <= 2 * max(r1, r2)){
            cout << "YES\n";
            continue;
        }

        if(d <= (r1 + r2) * (r1 + r2) &&
            k <= r1 + r2 + sqrtl(dx * dx + dy * dy)){
                cout << "YES\n";
        } else cout << "NO \n";
    }
}