#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int gcd_ext(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, x; cin >> a >> x;
    // xy = 1 mod a
    // xy - 1 = ca <-> xy - ca = 1 <-> xy + (-c)a = 1
    if(__gcd(x, a) > 1) cout << "-1\n";
    else {
        int y, c;
        gcd_ext(x, a, y, c);
        y %= a;
        if(y < 0) y += a;
        if(y == 1) y += a;
        cout << y << '\n';
    }
}