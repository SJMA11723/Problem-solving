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

#define MAXN 100000

struct _node{
    int x;
    ll p;
    int freq, cnt, rev;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(int _x) : x(_x), p(seed()), freq(1), cnt(1), rev(0),
        l(nullptr), r(nullptr){}
    void recalc(){
        cnt = freq;
        cnt += (l ? l->cnt : 0) + (r ? r->cnt : 0);
    }
};
using node = _node*;
_node pool[MAXN + 1];
int nxt_node = 1;
node alloc(int x){
    pool[nxt_node] = _node(x);
    return &pool[nxt_node++];
}
struct treap{
    node root;
    treap() : root(nullptr){}
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

    pair<node, node> split_v(node u, int d){
        if(!u) return {u, u};
        if(u->x < d){
            auto p = split_v(u->r, d);
            u->r = p.fi;
            u->recalc();
            return {u, p.se};
        } else {
            auto p = split_v(u->l, d);
            u->l = p.se;
            u->recalc();
            return {p.fi, u};
        }
    }

    void insert_v(int x){
        node l, m, r;
        tie(l, r) = split_v(root, x);
        tie(m, r) = split_v(r, x + 1);
        if(m){
            m->freq++;
            m->cnt++;
        } else m = alloc(x);
        root = merge(l, merge(m, r));
    }

    void erase_v(int x){
        node l, m, r;
        tie(l, r) = split_v(root, x);
        tie(m, r) = split_v(r, x + 1);
        if(!m || m->freq == 1) m = nullptr;
        else {
            m->freq--;
            m->cnt--;
        }
        root = merge(l, merge(m, r));
    }

    int count(int x){
        node l, r;
        tie(l, r) = split_v(root, x);
        int res = l ? l->cnt : 0;
        root = merge(l, r);
        return res;
    }

    int kth(int k){
        if(!root) return -1;
        node cur = root;
        while(k){
            int cntl = cur->l ? cur->l->cnt : 0;
            if(k <= cntl) cur = cur->l;
            else if(k <= cntl + cur->freq) return cur->x;
            else {
                k -= cntl + cur->freq;
                cur = cur->r;
            }
        }
        return cur->x;
    }

    int size(){
        return root ? root->cnt : 0;
    }
};

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    
    int t; cin >> t;
    rep(tt, 1, t + 1){
        cout << "Test : " << tt << '\n';

        int n; cin >> n;
        int A[n];
        rep(i, 1, n + 1) cin >> A[i];
        if(A[1] != 0){
            cout << "-1\n";
            continue;
        }

        treap arr;
        rep(i, 1, n + 1) arr.insert_v(i);

        bool ok = 1;
        int H[n + 1];
        repr(i, 1, n + 1){
            if(A[i] >= i){
                ok = 0;
                break;
            }
            H[i] = arr.kth(i - A[i]);
            arr.erase_v(H[i]);
        }

        if(ok) rep(i, 1, n + 1) cout << H[i] << " \n"[i == n];
        else cout << "-1\n";

        nxt_node = 1;
    }
}