#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, 1e18);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){string sep;for(const T &x : v) os << sep << x, sep = " "; return os;}

#define PRINT(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

const int MOD = 1e9 + 7;

#define MAXVAL 1000000
const ll INF = 1e12;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vpii edges[MAXVAL + 1];
    for(int i = 0; i < m; ++i){
        int idx, d, c; cin >> idx >> d >> c;
        edges[c].pb({idx - 1, d});
    }

    vi queries[MAXVAL + 1];
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int w; cin >> w;
        queries[w].pb(i);
    }

    ll ans[q];
    ll sum = INF * (n - 1);
    vll best_edge(n, INF);
    for(int w = MAXVAL; 0 < w; --w){
        for(auto [i, d] : edges[w]){
            sum += min(best_edge[i], (ll)d) - best_edge[i];
            best_edge[i] = min(best_edge[i], (ll)d);
        }

        for(int i : queries[w]) ans[i] = sum;
    }

    for(int i = 0; i < q; ++i)
        if(ans[i] < INF) cout << ans[i] << '\n';
        else cout << "impossible\n";
}
