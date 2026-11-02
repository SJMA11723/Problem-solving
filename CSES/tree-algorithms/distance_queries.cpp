/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/
#include <bits/stdc++.h>
using namespace std;
// typedef
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// define
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define repr(i,a,b) for(int i = (b) - 1; (a) <= i; --i)
const int MOD = 1e9 + 7;

// --- --- --- --- EXTTRAS --- --- --- --- 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef __int128_t lll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);


// --- --- --- --- LOGGER SETUP --- --- --- --- 
// Daclare before   
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v);
// Overload for std::pair
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.fi << ", " << p.se << ')';
}
// Overload for Containers (excluding std::string) SFINAE
template<typename C, typename T>
ostream& operator<<(ostream &os, const C &v) {
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
// Colors
constexpr const char *RST="\033[0m", *GREEN="\033[1;32m", 
*YELLOW="\033[1;33m",*CYAN="\033[1;36m",*RED="\033[1;31m";
// Logger Function
template<typename ...Args>
void logger(const char* col, string vars, Args&&... values){
    cerr << col << '[' << vars << "] =" << RST;
    ((cerr << " [" << values << ']'), ...);
    cerr << '\n';
}

// --- --- --- --- DEBUGGER SETUP --- --- --- ---    
#ifdef LOCAL
    #define DEBUG   if (true)
    #define SALTO   (cerr << '\n')  
    #define LOG(...)   logger("", #__VA_ARGS__, __VA_ARGS__)
    #define LOGC(c, ...) logger(c, #__VA_ARGS__, __VA_ARGS__)    
    #define COL(c, ...) (cerr << c << __VA_ARGS__ << RST << '\n')
#else
    #define DEBUG   if (false) 
    #define SALTO
    #define LOG(...)
    #define LOGC(...)
    #define COL(...)
#endif

#define LOGN 19
#define is_on(S, i) ((S) & (1 << (i)))

vvi T, P;
vi depth;

void precalc(int u, int p = 0){
    depth[u] = depth[p] + 1; P[0][u] = p;
    rep(k, 1, LOGN + 1) P[k][u] = P[k - 1][P[k - 1][u]];
    for(int v : T[u]) if(v != p) precalc(v, u);
}

int LCA(int a, int b){
    if(depth[b] < depth[a]) swap(a, b);
    int diff = depth[b] - depth[a];
    repr(k, 0, LOGN + 1) if(is_on(diff, k)) b = P[k][b];
    if(a == b) return a;
    repr(k, 0, LOGN + 1) if(P[k][a] != P[k][b]){
        a = P[k][a];
        b = P[k][b];
    }
    return P[0][a];
}

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    
    int n, q; cin >> n >> q;
    T.resize(n + 1);
    P.resize(LOGN + 1, vi(n + 1));
    depth.resize(n + 1);

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        T[a].pb(b);
        T[b].pb(a);
    }
    precalc(1);
    while(q--){
        int a, b; cin >> a >> b;
        int L = LCA(a, b);
        cout << depth[a] + depth[b] - 2 * depth[LCA(a, b)] << '\n';
    }
}