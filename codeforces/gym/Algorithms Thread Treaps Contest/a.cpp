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
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ale(1, LLONG_MAX);


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

#define MAXN 500000

struct _node{
    ll x, p;
    int freq, cnt;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(ll _x): x(_x), p(seed()), freq(1), cnt(1),
        l(nullptr), r(nullptr){}
    void recalc(){
        cnt = freq;
        cnt += ((l) ? l->cnt : 0) + ((r) ? r->cnt : 0);
    }
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(ll _x){
    pool[nxt_node] = _node(_x);
    return &pool[nxt_node++];
}


struct implicit_treap{
    node root;
    implicit_treap(): root(nullptr){}

    node merge(node l, node r){
        if(!l || !r) return l ? l : r;
        if(l->p < r->p){
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        } else {
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        }
    }

    pair<node, node> split_p(node u, int pos){
        if(!u) return {u, u};
        int cur_pos = (u->l) ? (u->l->cnt) : 0;
        if(cur_pos < pos){
            auto p = split_p(u->r, pos - cur_pos - 1);
            u->r = p.fi;
            u->recalc();
            return {u, p.se};
        } else {
            auto p = split_p(u->l, pos);
            u->l = p.se;
            u->recalc();
            return {p.fi, u};
        }
    }

    void insert_p(int pos, ll x){
        node l, r;
        tie(l, r) = split_p(root, pos);
        root = merge(merge(l, alloc(x)), r);
    }

    void erase_p(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        m = nullptr;
        root = merge(l, r);
    }

    void swap(int a, int b, int c, int d){
        node prv, A, mid, C, nxt;
        tie(C, nxt) = split_p(root, d + 1);
        tie(mid, C) = split_p(C, c);
        tie(A, mid) = split_p(mid, b + 1);
        tie(prv, A) = split_p(A, a);
        root = merge(prv, merge(C, merge(mid, merge(A, nxt))));
    }

    void _print(node u){
        if(!u) return;
        _print(u->l);
        cout << u->x << ' ';
        _print(u->r);
    }

    void print(){ _print(root); }
};

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int n; cin >> n;
    implicit_treap arr;
    rep(i, 0, n) arr.insert_p(i, i + 1);

    rep(i, 0, n){
        int a, b; cin >> a >> b;
        a--, b--;
        if(b <= a) continue;
        int len = min(b - a, n - b);
        arr.swap(a, a + len - 1, b, b + len - 1);
    }

    arr.print(); cout << '\n';
}