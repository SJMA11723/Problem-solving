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
//#define print(...) logger()

#define MAXN 1000000
int lp[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i <= MAXN; ++i){
        if(lp[i]) continue;
        lp[i] = i;
        for(ll j = 1ll * i * i; j <= MAXN; j += i)
            lp[j] = i;
    }

    int n; cin >> n;
    vvi cub(MAXN + 1);
    int len = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        while(x > 1){
            int p = lp[x];
            while(x % p == 0) x /= p;
            cub[p].push_back(x);
            if(len < cub[p].size()){
                len = cub[p].size();
                ans = p;
            }
        }
    }

    cout << ans << '\n';
}