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

const int MAXN = 50005;
int id_bloque[MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int t; cin >> t;

    int n; string s;

    
    while( t-- ){
        cin >> n >> s;
        s += '.';
        vi firstpos(1), len(1), dp(1, INT_MAX);
        int cur_block = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'x'){
                if(sz(dp) == cur_block){
                    dp.pb(INT_MAX);
                    firstpos.pb(i);
                    len.pb(0);
                }
                len[cur_block]++;
            } else if(cur_block < sz(dp)) cur_block++;
        }
        dp[cur_block] = 0;
        for(int i = cur_block - 1; 0 <= i; --i){
            int max_jump = (firstpos[i] + len[i] - 1) + len[i];
            for(int j = i + 1; j <= cur_block && firstpos[j] <= max_jump; ++j)
                dp[i] = min(dp[i], dp[j]);
            if(dp[i] != INT_MAX) dp[i]++;
        }
        cout << (dp[0] == INT_MAX ? -1 : dp[0]) << '\n';
    }
}