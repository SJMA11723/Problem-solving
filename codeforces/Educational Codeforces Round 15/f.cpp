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

#define MAXN 200000 // hide

struct _node{
    ll p;
    pii x;
    int ans, lz1, lz2, freq, cnt;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(int _x, int _i): p(seed()), x(pii(_x, _i)), ans(0), lz1(0), lz2(0), freq(1), cnt(1),
        l(nullptr), r(nullptr){}
};
using node = _node*;
_node pool[MAXN + 2];

int nxt_node = 1;
node alloc(int _x, int i){
    pool[nxt_node] = _node(_x, i);
    return &pool[nxt_node++];
}

int cnt(node u){return u ? u->cnt : 0;}

void apply_lz(node u){
    u->x.fi -= u->lz1;
    u->ans += u->lz2;
    u->lz1 = u->lz2 = 0;
}

void push(node u){
    if(u && (u->lz1 || u->lz2)){
        if(u->l){
            u->l->lz1 += u->lz1;
            u->l->lz2 += u->lz2;
        }
        if(u->r){
            u->r->lz1 += u->lz1;
            u->r->lz2 += u->lz2;
        }
        apply_lz(u);
    }
}

void recalc(node u){
    push(u->l); push(u->r); /// importante para lazy
    u->cnt = u->freq + cnt(u->l) + cnt(u->r);
}

struct treap{
    node root;
    treap(): root(nullptr){}

    node merge(node l, node r){
        push(l); push(r);
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

    pair<node, node> split_v(node u, pii d){
        if(!u) return {u, u};
        push(u);
        if(u->x < d){
            auto p = split_v(u->r, d);
            u->r = p.fi;
            recalc(u);
            return {u, p.se};
        } else {
            auto p = split_v(u->l, d);
            u->l = p.se;
            recalc(u);
            return {p.fi, u};
        }
    }

    void insert_v(int x, int i){
        node l, m, r;
        tie(l, r) = split_v(root, pii(x, i));
        m = alloc(x, i);
        root = merge(merge(l, m), r);
    }

    node unite(node t1, node t2){
        push(t1);
        push(t2);
        if(!t1 || !t2) return t1 ? t1 : t2;
        if(t1->p < t2->p) swap(t1, t2);
        node lt, rt; tie(lt, rt) = split_v(t2, t1->x);
        t1->l = unite(t1->l, lt);
        t1->r = unite(t1->r, rt);
        recalc(t1);
        return t1;
    }

    void add_tshirt(int price){
        node l, r;
        tie(l, r) = split_v(root, pii(price, INT_MIN));
        if(r){
            r->lz1 += price;
            r->lz2++;
        }
        root = unite(l, r);
    }

    void get_ans(int ans[]){
        queue<node> q;
        q.push(root);
        while(sz(q)){
            node cur = q.front(); q.pop();
            if(!cur) continue;
            push(cur);
            ans[cur->x.se] = cur->ans;
            q.push(cur->l);
            q.push(cur->r);
        }
    }
};

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    
    int n; cin >> n;
    pii tshirt[n];
    for(pii &ts : tshirt) cin >> ts.fi >> ts.se;
    sort(tshirt, tshirt + n, [&](pii &A, pii &B){
        if(A.se == B.se) return A.fi < B.fi;
        return A.se > B.se;
    });

    treap customers;
    int k; cin >> k;
    rep(i, 0, k){
        int bi; cin >> bi;
        customers.insert_v(bi, i);
    }

    for(pii &ts : tshirt) customers.add_tshirt(ts.fi);
    int ans[k];
    customers.get_ans(ans);
    rep(i, 0, k) cout << ans[i] << " \n"[i + 1 == k];
}