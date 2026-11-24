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
    int x, freq, cnt, lz;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(int _x): p(seed()), x(_x), freq(1), cnt(1), lz(0),
        l(nullptr), r(nullptr){}
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(int _x){
    pool[nxt_node] = _node(_x);
    return &pool[nxt_node++];
}

int cnt(node u){return u ? u->cnt : 0;}

void apply_lz(node u){
    u->x += u->lz;
    u->lz = 0;
}

void push(node u){
    if(u && u->lz){
        if(u->l) u->l->lz += u->lz;
        if(u->r) u->r->lz += u->lz;
        apply_lz(u);
    }
}

void recalc(node u){
    push(u->l); push(u->r); /// importante para lazy
    u->cnt = u->freq + cnt(u->l) + cnt(u->r);
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
        int cur_pos = cnt(u->l);
        if(cur_pos < pos){
            auto p = split_p(u->r, pos - cur_pos - 1);
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

    void push_back(int x){ root = merge(root, alloc(x)); }

    void erase_p(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        m = nullptr;
        root = merge(l, r);
    }

    int lower_bound(int x){
        node cur = root;
        int pos = 0;
        while(cur){
            push(cur);
            pos += cnt(cur->l);
            if(cur->x < x){
                pos++;
                cur = cur->r;
            } else {
                pos -= cnt(cur->l);
                cur = cur->l;
            }
        }
        return pos;
    }

    int at(int pos){
        node l, m, r;
        tie(l, r) = split_p(root, pos);
        tie(m, r) = split_p(r, 1);
        int res = m->x;
        root = merge(l, merge(m, r));
        return res;
    }

    int update_dp(int l, int r){
        int lpos = lower_bound(l);
        int rpos = lower_bound(r);
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, rpos + 1);
        tie(prv, inter) = split_p(inter, lpos);

        if(cnt(inter) == 1){
            inter->x = l;
            root = merge(prv, merge(inter, nxt));
            return lpos + 1;
        }

        node first, last;
        tie(first, last) = split_p(inter, inter->cnt - 1);
        first->lz++; // suma 1 a todos excepto el último
        inter = merge(last, first); // right shift
        tie(first, last) = split_p(inter, 1);
        first->x = l; // el primero es igual a l
        inter = merge(first, last);

        root = merge(prv, merge(inter, nxt));

        return rpos + 1;
    }

    void _print(node u){
        if(!u) return;
        push(u);
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
    implicit_treap dp;
    int ans = 0;
    rep(i, 0, n){
        int l, r; cin >> l >> r;
        dp.pb(2e9);
        ans = max(ans, dp.update_dp(l, r));
    }
    cout << ans << '\n';
}