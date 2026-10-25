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

const int MOD = 1e9 + 7;

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

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int n, m; cin >> n >> m;
    int arr[n];
    set<int> cub[m + 1], cubrev[m + 1];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        cub[arr[i]].insert(i);
        cubrev[arr[i]].insert(n - 1 - i);
    }

    int len = 0;
    for(int i = 1; i <= m; ++i) len += sz(cub[i]) > 0;

    int idx = 1, idxrev = 1, min_ops = 0;
    while(idx <= m){
        int last = -1;
        for(; idx <= m; ++idx){
            if(sz(cub[idx]) == 0) continue;
            auto it = cub[idx].lower_bound(last);
            if(it == cub[idx].end()) break;
            last = *it;
        }

        last = -1;
        for(; idxrev <= m; ++idxrev){
            if(sz(cubrev[idxrev]) == 0) continue;
            auto it = cubrev[idxrev].lower_bound(last);
            if(it == cubrev[idxrev].end()) break;
            last = *it;
        }

        min_ops++;
        idx = idxrev = max(idx, idxrev);
    }

    cout << len << ' ' << min_ops << '\n';
}

