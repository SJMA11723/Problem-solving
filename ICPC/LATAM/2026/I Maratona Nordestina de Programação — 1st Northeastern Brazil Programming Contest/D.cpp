#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ull;
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


#define is_on( S, j ) (S & (1ll << (j)))
#define set_bit( S, j) (S |= (1ll << (j)))
#define clear_bit( S, j) (S &= ~(1ll << (j)))

ull invert( ll s, int k){
    // los primeros k bits son el mismo
    ull x = 0;
    for( int i=0; i<k; i++){
        if( is_on(s,i) ) set_bit( x, i);
    }

    for( int i=k; i<=31; i++){
        if( is_on(s,i) && is_on(x,i-k) ) clear_bit(x, i);
        if( !is_on(s,i) && is_on(x,i-k) ) set_bit(x, i);
        if( is_on(s,i) && !is_on(x,i-k) ) set_bit(x, i);
        if( !is_on(s,i) && !is_on(x,i-k) ) clear_bit(x, i);
    }

    return x;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    ull s; cin >> s;
    ull x = s;

    for( int i=1; i<=n; i++){
        x = invert( x, k);
    }

    cout << x << "\n";

}