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

#define MAXN 300000

struct _node{
    ll p;
    int x, freq, cnt, cnt1, pref0, pref1, suff0, suff1, max_range;
    int rev, xor1, lzupt;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(int _x): p(seed()), x(_x), freq(1), cnt(1), cnt1(_x),
        pref0(_x ^ 1), pref1(_x), suff0(_x ^ 1), suff1(_x),
        max_range(1), rev(0), xor1(0), lzupt(0), l(nullptr), r(nullptr){}
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(int _x){
    pool[nxt_node] = _node(_x);
    return &pool[nxt_node++];
}

int cnt(node u){return u ? u->cnt : 0;}
int cnt1(node u){return u ? u->cnt1 : 0;}
int pref0(node u){return u ? u->pref0 : 0;}
int pref1(node u){return u ? u->pref1 : 0;}
int suff0(node u){return u ? u->suff0 : 0;}
int suff1(node u){return u ? u->suff1 : 0;}
int max_range(node u){return u ? u->max_range : 0;}

void apply_lz(node u){
    if(u->rev){
        swap(u->l, u->r);
        swap(u->pref0, u->suff0);
        swap(u->pref1, u->suff1);
    }
    if(u->lzupt){
        u->x = u->lzupt - 1;
        u->cnt1 = u->x ? cnt(u) : 0;
        u->pref0 = u->cnt - u->cnt1;
        u->suff1 = u->cnt1;
        u->pref1 = u->pref0 ? 0 : u->suff1;
        u->suff0 = u->suff1 ? 0 : u->pref0;
        u->max_range = max(u->cnt1, u->cnt - u->cnt1);
    }
    if(u->xor1){
        u->x ^= 1;
        u->cnt1 = u->cnt - u->cnt1;
        swap(u->pref0, u->pref1);
        swap(u->suff0, u->suff1);
    }
    u->rev = u->xor1 = u->lzupt = 0;
}

void push(node u){
    if(!u) return;
    if(u->rev){
        if(u->l) u->l->rev ^= 1;
        if(u->r) u->r->rev ^= 1;
    }
    if(u->lzupt){
        if(u->l){
            u->l->lzupt = u->lzupt;
            u->l->xor1 = 0;
        }
        if(u->r){
            u->r->lzupt = u->lzupt;
            u->r->xor1 = 0;
        }
    }
    if(u->xor1){
        if(u->l) u->l->xor1 ^= 1;
        if(u->r) u->r->xor1 ^= 1;
    }
    apply_lz(u);
}

void recalc(node u){
    push(u->l); push(u->r); /// importante para lazy
    
    u->cnt = u->freq + cnt(u->l) + cnt(u->r);
    u->cnt1 = (u->x == 1) + cnt1(u->l) + cnt1(u->r);
    u->pref0 = pref0(u->l) + (pref0(u->l) == cnt(u->l)) * (u->x == 0) * (1 + pref0(u->r));
    u->pref1 = pref1(u->l) + (pref1(u->l) == cnt(u->l)) * (u->x == 1) * (1 + pref1(u->r));
    u->suff0 = suff0(u->r) + (suff0(u->r) == cnt(u->r)) * (u->x == 0) * (1 + suff0(u->l));
    u->suff1 = suff1(u->r) + (suff1(u->r) == cnt(u->r)) * (u->x == 1) * (1 + suff1(u->l));
    u->max_range = max({max_range(u->l), max_range(u->r), 1 + (u->x ? suff1(u->l) + pref1(u->r) : suff0(u->l) + pref0(u->r))});
}

struct implicit_treap{
    node root;
    implicit_treap(): root(nullptr){}
    
    node merge(node l, node r){
        push(l);
        push(r);
        if(!l || !r) return l ? l : r;
        if(l->p < r->p){
            r->l = merge(l, r->l);
            recalc(r);
            return r;
        } else {
            l->r = merge(l->r, r);
            recalc(l);
            return l;
        }
    }

    pair<node, node> split_p(node u, int pos){
        if(!u) return {u, u};
        push(u);
        if(cnt(u->l) < pos){
            auto p = split_p(u->r, pos - cnt(u->l) - 1);
            u->r = p.fi;
            recalc(u);
            return {u, p.se};
        } else {
            auto p = split_p(u->l, pos);
            u->l = p.se;
            recalc(u);
            return {p.fi, u};
        }
    }

    void insert_p(int pos, int x){
        node l, r;
        tie(l, r) = split_p(root, pos);
        root = merge(merge(l, alloc(x)), r);
    }

    void push_back(int x){
        root = merge(root, alloc(x));
    }

    void erase_p(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        m = nullptr;
        root = merge(l, r);
    }

    void reverse(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        inter->rev ^= 1;
        root = merge(prv, merge(inter, nxt));
    }

    void xor1(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        inter->xor1 ^= 1;
        root = merge(prv, merge(inter, nxt));
    }

    void sort(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        node l0, r1;
        tie(l0, r1) = split_p(inter, cnt(inter) - cnt1(inter));
        if(l0) l0->lzupt = 1;
        if(r1) r1->lzupt = 2;
        inter = merge(l0, r1);
        root = merge(prv, merge(inter, nxt));
    }

    int max_range(){
        push(root);
        return root->max_range;
    }

    void _print(node u){
        if(!u) return;
        push(u);
        _print(u->l);
        cout << u->x;
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
    
    int n, q; cin >> n >> q;
    implicit_treap arr;
    rep(i, 0, n){
        char c; cin >> c;
        arr.pb(c - '0');
    }

    
    while(q--){
        int t, l, r; cin >> t >> l >> r; l--, r--;
        if(t == 1) arr.xor1(l, r);
        else if(t == 2) arr.reverse(l, r);
        else arr.sort(l, r);
        cout << arr.max_range() << '\n';
    }
}