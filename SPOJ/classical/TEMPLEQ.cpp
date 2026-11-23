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

inline char gc() {
    static char buf[1 << 16];
    static size_t len = 0, pos = 0;
    if (pos == len) {
        pos = 0;
        len = fread(buf, 1, sizeof(buf), stdin);
        if (!len) return EOF;
    }
    return buf[pos++];
}

inline bool read_int(int &x) {
    char c = gc();
    bool neg = false;
    while (c != EOF && (c < '0' || c > '9') && c != '-') c = gc();
    if (c == EOF) return false;
    if (c == '-') { neg = true; c = gc(); }
    x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = gc();
    }
    if (neg) x = -x;
    return true;
}

char out_buf[1 << 16];
int out_pos = 0;
inline void flush_out() {
    fwrite(out_buf, 1, out_pos, stdout);
    out_pos = 0;
}

inline void write_int(int x) {
    if (out_pos > (1 << 15)) flush_out();
    if (x < 0) { out_buf[out_pos++] = '-'; x = -x; }
    if (x == 0) { out_buf[out_pos++] = '0'; out_buf[out_pos++] = '\n'; return; }
    char tmp[16];
    int len = 0;
    while (x > 0) { tmp[len++] = char('0' + (x % 10)); x /= 10; }
    while (len--) out_buf[out_pos++] = tmp[len];
    out_buf[out_pos++] = '\n';
}

#define MAXN 600000

struct _node{
    ll x, p;
    int freq, cnt, lz;
    _node *l, *r, *P;
    _node() : l(nullptr), r(nullptr), P(nullptr){}
    _node(ll _x): x(_x), p(seed()), freq(1), cnt(1), lz(0),
        l(nullptr), r(nullptr), P(nullptr){}
    void recalc(){
        cnt = freq + (l ? l->cnt : 0) + (r ? r->cnt : 0);
        if(l) l->P = this;
        if(r) r->P = this;
    }
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(ll _x){
    pool[nxt_node] = _node(_x);
    return &pool[nxt_node++];
}

int cnt(node u){return u ? u->cnt : 0;}

struct implicit_treap{
    node root;
    implicit_treap(): root(nullptr){}

    void apply_lz(node u){
        u->x -= u->lz;
        u->lz = 0;
    }

    void push(node u){
        if(u && u->lz){
            if(u->l) u->l->lz += u->lz;
            if(u->r) u->r->lz += u->lz;
            apply_lz(u);
        }
    }
    
    node merge(node l, node r){
        push(l);
        push(r);
        if(!l || !r) return l ? l : r;
        if(l->p < r->p){
            r->l = merge(l, r->l);
            r->recalc();
            r->P = nullptr;
            return r;
        } else {
            l->r = merge(l->r, r);
            l->recalc();
            l->P = nullptr;
            return l;
        }
    }

    pair<node, node> split_p(node u, int pos){
        if(!u) return {u, u};
        push(u);
        int cur_pos = cnt(u->l);
        if(cur_pos < pos){
            auto p = split_p(u->r, pos - cur_pos - 1);
            u->r = p.fi;
            u->recalc();
            if(p.se) p.se->P = nullptr;
            return {u, p.se};
        } else {
            auto p = split_p(u->l, pos);
            u->l = p.se;
            u->recalc();
            if(p.fi) p.fi->P = nullptr;
            return {p.fi, u};
        }
    }

    node insert_p(int pos, ll x){
        node l, r;
        tie(l, r) = split_p(root, pos);
        node u = alloc(x);
        root = merge(merge(l, u), r);
        return u;
    }

    node push_back(ll x){
        node u = alloc(x);
        root = merge(root, u);
        return u;
    }

    int erase_p(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        int res = m->x;
        m = nullptr;
        root = merge(l, r);
        return res;
    }

    int erase_p(node u){
        if(!u) return -1;
        vector<node> ancestors;
        node P = u->P;
        while(P){
            ancestors.pb(P);
            P = P->P;
        }
        repr(i, 0, sz(ancestors)) push(ancestors[i]);
        push(u);
        int res = u->x;
        if(u == root) root = merge(u->l, u->r);
        else {
            P = u->P;
            if(P->l == u) P->l = merge(u->l, u->r);
            else P->r = merge(u->l, u->r);
            rep(i, 0, sz(ancestors)) ancestors[i]->recalc();
        }
        return res;
    }

    int lower_bound(int val){
        node cur = root;
        int res = 0;
        while(cur){
            push(cur);
            if(cur->x < val){
                res += cnt(cur->l) + 1; 
                cur = cur->r;
            } else cur = cur->l;
        }
        return res;
    }

    void open(int pos){
        node l, r;
        tie(l, r) = split_p(root, pos);
        if(r) r->lz++;
        root = merge(l, r);
    }

    void _print(node u){
        if(!u) return;
        push(u);
        _print(u->l);
        cout << u->x << ' ';
        _print(u->r);
    }

    void print(){ _print(root); }

    int size(){return cnt(root);}
};

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    
    int n; read_int(n);
    int q; read_int(q);
    pii arr[n];
    rep(i, 0, n){
        read_int(arr[i].fi);
        arr[i].se = i;
    }
    sort(arr, arr + n);
    node cur_node[n];
    implicit_treap ord_arr;
    rep(i, 0, n) cur_node[arr[i].se] = ord_arr.pb(arr[i].fi);

    while(q--){
        int t; read_int(t);
        if(t == 1){
            int idx; read_int(idx); idx--;
            int val = ord_arr.erase_p(cur_node[idx]) + 1;
            cur_node[idx] = ord_arr.insert_p(ord_arr.lower_bound(val), val);
        } else if(t == 2){
            int x; read_int(x);
            write_int(sz(ord_arr) - ord_arr.lower_bound(x));
        } else {
            int y; read_int(y);
            ord_arr.open(ord_arr.lower_bound(y));
        }
    }
    flush_out();
}