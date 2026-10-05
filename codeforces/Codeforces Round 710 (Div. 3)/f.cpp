/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define fi first
#define se second

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

// =============== DEBUG ============
const bool deb = 0;
#define DEBUG if(deb)

template<typename A, typename B> ostream & operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
// ==================================

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pii arr[n];
        for(pii &p : arr) cin >> p.fi;
        for(pii &p : arr) cin >> p.se;
        sort(arr, arr + n);
        ll ans = 0;
        pii cur_node = {1, 1};
        for(pii &p : arr){
            if(cur_node == p) continue;
            int sum = cur_node.fi + cur_node.se;
            if(cur_node.fi - cur_node.se < p.fi - p.se){
                if(sum % 2 == 0) cur_node.fi++;
                cur_node.fi += p.se - cur_node.se;
                cur_node.se = p.se;
                ans += (abs(cur_node.fi - p.fi) + 1) / 2;
                cur_node.fi = p.fi - p.se + cur_node.se;
            } else if(sum % 2 == 0) ans += p.fi - cur_node.fi;
            cur_node = p;
        }
        cout << ans << '\n';
    }
}