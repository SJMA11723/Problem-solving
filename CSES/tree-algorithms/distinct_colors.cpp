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

#define MAXN 200000
 
vi sub, depth, compress_color, color, ans, cnt;
vvi T;
vector<bool> big;
 
int idx(int c){
    return lower_bound(all(compress_color), c) - compress_color.begin();
}
 
int precalc(int u, int p = 0){
    depth[u] = depth[p] + 1;
    for(int v : T[u]) if(v != p) sub[u] += precalc(v, u);
    return ++sub[u];
}

ll ops = 0;
int distinct_colors = 0;
void add(int u, int x, int p = 0){
    ops++;
    cnt[color[u]] += x;
    if(cnt[color[u]] == 0) distinct_colors--;
    else if(cnt[color[u]] == 1 && x == 1) distinct_colors++;
    for(int v : T[u]) if(v != p && !big[v]) add(v, x, u);
}
 
void dfs(int u, bool keep, int p = 0){
    int maxi = -1, big_child = -1;
    for(int v : T[u]) if(v != p && sub[v] > maxi)
        maxi = sub[v], big_child = v;
    for(int v : T[u]) if(v != p && v != big_child) dfs(v, 0, u);
    if(big_child != -1) dfs(big_child, 1, u), big[big_child] = 1;
    add(u, 1, p);
    ans[u] = distinct_colors;
    if(big_child != -1) big[big_child] = 0;
    if(!keep) add(u, -1, p);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    T.resize(n + 1);
    ans.resize(n + 1);
    sub.resize(n + 1);
    depth.resize(n + 1);
    big.resize(n + 1);
    color.resize(n + 1);
    for(int i = 1; i <= n; ++i) cin >> color[i];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        T[a].pb(b);
        T[b].pb(a);
    }
    compress_color = color;
    sort(all(compress_color));
    compress_color.resize(unique(all(compress_color)) - compress_color.begin());
    cnt.resize(sz(compress_color));
    for(int &c : color) c = idx(c);
 
    precalc(1);
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}