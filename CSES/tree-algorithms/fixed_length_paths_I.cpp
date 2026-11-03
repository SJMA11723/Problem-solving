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

struct CT{
    vvi tree;
    vi sub, cnt;
    vector<bool> removed;
    ll ans;
    int k;

    CT(vvi &T, int _k) : tree(T){
        int n = sz(T);
        sub.resize(n);
        removed.resize(n);
        ans = 0;
        k = _k;
        cnt.resize(k + 1);
        build(0);
    }

    int find_sub(int u, int p = -1){
        sub[u] = 1;
        for(int v : tree[u]) if(v != p && !removed[v]) sub[u] += find_sub(v, u);
        return sub[u];
    }

    int find_centroid(int u, int n, int p = -1){
        for(int v : tree[u]) if(v != p && sub[v] > n / 2 && !removed[v])
            return find_centroid(v, n, u);
        return u;
    }

    void count_dist(int u, vi &dist, int p = -1, int d = 1){
        dist.pb(d);
        if(d == k) return;
        for(int v : tree[u]) if(v != p && !removed[v]) count_dist(v, dist, u, d + 1);
    }

    void build(int u, int p = -1){
        int n = find_sub(u, p);
        int centroid = find_centroid(u, n, p);
        if(p == -1) p = centroid;
        
        removed[centroid] = 1;
        
        vi adj(all(tree[centroid]));
        vi dist, alldist;
        cnt[0] = 1;
        for(int v : adj){
            if(removed[v]) continue;
            
            count_dist(v, dist, centroid);
            for(int d : dist) if(d <= k) ans += cnt[k - d];
            for(int d : dist){
                cnt[d]++;
                alldist.pb(d);
            }
            dist.clear();
        }
        for(int d : alldist) cnt[d]--;

        for(int v : adj) if(!removed[v]) build(v, centroid);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vvi tree(n);
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    CT T(tree, k);
    cout << T.ans << '\n';
}