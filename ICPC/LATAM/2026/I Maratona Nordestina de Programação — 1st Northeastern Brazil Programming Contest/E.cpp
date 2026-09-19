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

template<typename A, typename B> ostream&operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){
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

const bool deb = 0;
#define DEBUG if(deb)

int main(){
    int n; cin >> n;

    int l = 1, r = n;
    while(l < r){
        int len = max(1, (r - l) / 3);
        cout << "? " << len << ' ';
        for(int i = 0; i < len; ++i) cout << l + i << ' ';
        for(int i = 0; i + 1 < len; ++i) cout << l + len + i << ' ';
        cout << l + len + len - 1 << endl;
        char c; cin >> c;
        if(c == 'E') r = l + len - 1;
        else if(c == 'D'){
            l += len;
            r = l + len - 1;
        } else l += 2 * len;
    }
    cout << "! " << r << endl;
}