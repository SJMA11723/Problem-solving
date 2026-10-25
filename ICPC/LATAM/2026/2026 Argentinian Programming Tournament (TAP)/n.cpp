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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = (b); i < (b); ++i)

const int MOD = 998244353;

template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream  &os, const C &v);

template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}

template<typename C, typename T>
ostream& operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
constexpr const char *RST="\033[0m", *GREEN="\033[1;32m",
*YELLOW="\033[1;33m", *CYAN="\033[1;36m", *RED="\033[1;31m";

template<typename ...Args>
void logger(const char *col, string vars, Args&&... values){
    cerr << col << '[' << vars << "] = " << RST;
    ((cerr << " [" << values << ']'), ...);
    cerr << '\n';
}


#ifdef LOCAL
    #define DEBUG if(true)
    #define SALTO (cerr << '\n')
    #define LOG(...) logger("", #__VA_ARGS__, __VA_ARGS__)
    #define LOGC(c, ...) logger(c, #__VA_ARGS__, __VA_ARGS__)
    #define COL(c, ...) (cerr << c << __VA_ARGS__ << RST << '\n')
#else 
    #define DEBUG if(false)
    #define SALGO 
    #define LOG(...)
    #define LOGC(c, ...)
    #define COL(c, ...)
#endif

#define MAXVAL 1000000

int fact[MAXVAL + 1], inv_fact[MAXVAL + 1];


int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int binom(int n, int k){
    if(n < 0 || k < 0 || k > n) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int f(int n, int k, const int A){
    if(!n && !k) return 1;
    if(k < 0 || n <= k) return 0;
    return 1ll * binom(n - 1, k) * A % MOD * bin_exp(A - 1, n - k - 1) % MOD;
}

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    fact[0] = 1;
    for(int i = 1; i <= MAXVAL; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXVAL] = bin_exp(fact[MAXVAL], MOD - 2);
    for(int i = MAXVAL; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int N, K, A; cin >> N >> K >> A;

    int ans = 0;
    for(int i = 0; i <= K; ++i){
        ans += 1ll * f(N / 2, i, A) * f((N + 1) / 2, K - i, A) % MOD;
        LOG(i, f(N / 2, i, A));
        LOG(K - i, f((N + 1) / 2, K - i, A));
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}

