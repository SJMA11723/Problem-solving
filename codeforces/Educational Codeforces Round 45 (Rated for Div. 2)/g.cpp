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

struct dsu{
    vi RA, P;

    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(all(P), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    int join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return 0;
        if(RA[x] >= RA[y]) swap(x, y);

        RA[y] += RA[x];
        P[x] = y;
        return 1;
    }
};

#define MAXN 200000
vi divs[MAXN + 1];

ll pairs(int n){
    return 1ll * n * (n - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= MAXN; ++i)
    for(int j = i; j <= MAXN; j += i) divs[j].pb(i);

    int n; cin >> n;
    int arr[n];
    vi cub[MAXN + 1];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        for(int d : divs[arr[i]]) cub[d].pb(i);
    }

    vi tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b; a--, b--;
        tree[a].pb(b);
    }

    ll cntg[MAXN + 1] = {};
    dsu gset(n);
    for(int i = MAXN; 0 < i; --i){
        if(!sz(cub[i])) continue;

        cntg[i] += sz(cub[i]);
        for(int u : cub[i]) for(int v : tree[u]) if(arr[v] % i == 0){
            // estan en diferentes componentes porque es un arbol
            cntg[i] -= pairs(gset.RA[gset.root(u)]);
            cntg[i] -= pairs(gset.RA[gset.root(v)]);
            gset.join(u, v);
            cntg[i] += pairs(gset.RA[gset.root(u)]);
        }

        for(int j = 2 * i; j <= MAXN; j += i) cntg[i] -= cntg[j];
        for(int u : cub[i]){
            gset.P[u] = u;
            gset.RA[u] = 1;
        }
    }

    for(int i = 1; i <= MAXN; ++i) if(cntg[i]) cout << i << ' ' << cntg[i] << '\n';
}