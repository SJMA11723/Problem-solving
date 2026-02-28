#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

#define DEBUG if(deb)

const bool deb = true;
const int MOD = 1e9 + 7;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type> ostream& operator<<(ostream &os, const C &v){
    string sep; for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

struct treap{
    typedef struct _node{
        pii x;
        int freq, len, max_len;
        ll p;
        _node *l, *r;
        
        _node(int _x, int idx, int _len = 1) : x(make_pair(_x, idx)), p(( (ll)(rand()) << 32 ) ^ rand()), len(_len), max_len(_len), freq(1), l(nullptr), r(nullptr){}

        ~_node(){
            delete l;
            delete r;
        }

        void recalc(){
            max_len = len;
            max_len = max(max_len, ((l) ? l->max_len : 0));
            max_len = max(max_len, ((r) ? r->max_len : 0)); 
        }
    }* node;

    node root;

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

    void split_by_value(node n, pii d, node &l, node &r){
        l = r = nullptr;
        if(!n) return;
        if(n->x < d){
            split_by_value(n->r, d, n->r, r);
            l = n;
        } else {
            split_by_value(n->l, d, l, n->l);
            r = n;
        }
        n->recalc();
    }

    treap(): root(NULL){}

    void insert_value(pii x, int len){
        node l, m, r;
        split_by_value(root, x, l, m);
        
        x.se++;
        split_by_value(m, x, m, r);
        x.se--;

        if(m){
            m->freq++;
        } else {
            m = new _node(x.fi, x.se, len);
        }
        root = merge(merge(l, m), r);
    }

    void erase_value(pii x){
        node l, m, r;
        split_by_value(root, x, l, m);

        x.se++;
        split_by_value(m, x, m, r);
        x.se--;

        if(!m || m->freq == 1){
            delete m;
            m = nullptr;
        } else{
            m->freq--;
        }

        root = merge(merge(l, m), r);
    }

    int get_max_len(int h){
        node l, m, r;
        split_by_value(root, {h + 1, -1}, l, r);
        int res = r ? r->max_len : 0;
        root = merge(l, r);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        treap mset;
        int len = 1;
        for(int i = n - 1; 0 <= i; --i){
            mset.insert_value({arr[i], i}, len);

            if(i){
                if(arr[i - 1] < arr[i]) len++;
                else len = 1;
            }
        }

        len = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            mset.erase_value({arr[i], i});

            ans = max(ans, len + mset.get_max_len(arr[i]) );

            if(i + 1 < n){
                if(arr[i] < arr[i + 1]) len++;
                else len = 1;
            }
        }

        cout << ans << '\n';
    }
}