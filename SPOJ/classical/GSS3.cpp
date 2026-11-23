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
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ale(1, LLONG_MAX);

#define MAXN 600000

struct _node{
    ll p;
    int x, freq, cnt, rev, max_sum, max_pref, max_suff, sum;
    _node *l, *r;
    _node() : l(nullptr), r(nullptr){}
    _node(ll _x): p(seed()), x(_x), freq(1), cnt(1), rev(0),
        max_sum(_x), max_pref(_x), max_suff(_x), sum(_x),
        l(nullptr), r(nullptr){}
    void recalc(){
        cnt = freq + (l ? l->cnt : 0) + (r ? r->cnt : 0);
        sum = x + (l ? l->sum : 0) + (r ? r->sum : 0);
        max_sum = max({l ? l->max_sum : INT_MIN, r ? r->max_sum : INT_MIN,
                    max(0, (l ? l->max_suff : 0)) + x + max(0, (r ? r->max_pref : 0))});
        max_pref = max({l ? l->max_pref : INT_MIN, (l ? l->sum : 0) + x,
                        (l ? l->sum : 0) + x + (r ? r->max_pref : 0)});
        max_suff = max({r ? r->max_suff : INT_MIN, x + (r ? r->sum : 0),
                        (l ? l->max_suff : 0) + x + (r ? r->sum : 0)});
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
        u->rev = 0;
        swap(u->l, u->r);
    }

    void push(node u){
        if(u && u->rev){
            if(u->l) u->l->rev ^= 1;
            if(u->r) u->r->rev ^= 1;
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
            return r;
        } else {
            l->r = merge(l->r, r);
            l->recalc();
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
            return {u, p.se};
        } else {
            auto p = split_p(u->l, pos);
            u->l = p.se;
            u->recalc();
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
    
    void modify(int i, int x){
        node l, m, r;
        tie(l, r) = split_p(root, i);
        tie(m, r) = split_p(r, 1);
        if(m){
            m->x = x;
            m->recalc();
        }
        root = merge(l, merge(m, r));
    }

    int max_subarr_sum(int l, int r){
        node prv, inter, nxt;
        tie(inter, nxt) = split_p(root, r + 1);
        tie(prv, inter) = split_p(inter, l);
        int res = inter ? inter->max_sum : 0;
        root = merge(prv, merge(inter, nxt));
        return res;
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
    
    int n; cin >> n;
    implicit_treap arr;
    rep(i, 0, n){
        int Ai; cin >> Ai;
        arr.pb(Ai);
    }

    int m; cin >> m;
    while(m--){
        int t, x, y; cin >> t >> x >> y;
        if(t) cout << arr.max_subarr_sum(x - 1, y - 1) << '\n';
        else arr.modify(x - 1, y);
    }
}