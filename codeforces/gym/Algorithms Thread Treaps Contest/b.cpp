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

#define MAXN 600000

const int A = 911382323;
const int B = 972663749;
int pA[MAXN + 1];

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

struct _node{
    ll p;
    int freq, cnt, H, revH;
    char c;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(char _c): p(seed()), freq(1), cnt(1), H(_c), revH(_c), c(_c),
        l(nullptr), r(nullptr){}
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(char _x){
    pool[nxt_node] = _node(_x);
    return &pool[nxt_node++];
}

int cnt(node u){return u ? u->cnt : 0;}

int mhash(node u){return u ? u->H : 0;}
int mrevhash(node u){return u ? u->revH : 0;}

void apply_lz(node u){}

void push(node u){}

void recalc(node u){
    push(u->l); push(u->r); /// importante para lazy
    u->cnt = u->freq + cnt(u->l) + cnt(u->r);
    
    // hash de todo el subarreglo
    u->H = (1ll * mhash(u->l) * A + u->c) % B;
    u->revH = (1ll * mrevhash(u->r) * A + u->c) % B;
    
    u->H = (1ll * u->H * pA[cnt(u->r)] + mhash(u->r)) % B;
    u->revH = (1ll * u->revH * pA[cnt(u->l)] + mrevhash(u->l)) % B;
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

    void insert_p(int pos, char c){
        node l, r;
        tie(l, r) = split_p(root, pos);
        root = merge(merge(l, alloc(c)), r);
    }

    void push_back(char c){
        root = merge(root, alloc(c));
    }

    void erase_p(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        m = nullptr;
        root = merge(l, r);
    }

    void erase_range(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        root = merge(prv, nxt);
    }

    bool is_palin(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        
        int len = r - l + 1;
        node midl, c = nullptr, midr;
        tie(midl, midr) = split_p(inter, len / 2);
        if(len & 1) tie(c, midr) = split_p(midr, 1);
        bool res = mhash(midl) == mrevhash(midr);
        inter = merge(midl, merge(c, midr));

        root = merge(prv, merge(inter, nxt));

        return res;
    }

    void _print(node u){
        if(!u) return;
        push(u);
        _print(u->l);
        cout << u->c << ' ';
        _print(u->r);
    }

    void print(){ _print(root); }

    void print(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        _print(inter);
        root = merge(prv, merge(inter, nxt));
    }
};


int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    pA[0] = 1;
    rep(i, 1, MAXN) pA[i] = 1ll * A * pA[i - 1] % B;

    int n, q; cin >> n >> q;
    implicit_treap str;
    rep(i, 0, n){
        char c; cin >> c;
        str.pb(c);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r; l--, r--;
            str.erase_range(l, r);
        } else if(t == 2){
            char c; cin >> c;
            int p; cin >> p; p--;
            str.insert_p(p, c);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << (str.is_palin(l, r) ? "yes\n" : "no\n");
        }
    }
}