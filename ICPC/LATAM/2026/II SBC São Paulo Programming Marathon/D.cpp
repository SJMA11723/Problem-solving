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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string bar(n, '_'), bar_(n + 1, '_');
    cout << string(n, ' ') << bar_ << '\n';
    for(int i = 1; i < n; ++i) cout << string(n - i, ' ') << '/' << string(n + 2 * i - 1, ' ') << "\\\n";
    cout << '/' << bar << string(2 * n - 1, ' ') << '\\' << bar_ << '\n';
    for(int i = 1; i < n; ++i) cout << string(n + i, ' ') << '\\' << string(3 * n - 2 * i + 1, ' ') << "/\n";
    cout << string(2 * n, ' ') << '\\' << bar_ << "/\n";
}