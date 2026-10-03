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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

struct segment_tree{
    struct node{
        int mini, lazy;
        node() : mini(INT_MAX), lazy(0){}
        node(int x, int lz = 0) : mini(x), lazy(lz){}
        const node operator+(const node &b)const{
            return node(min(mini, b.mini));
        }
    };
    vector<node> nodes;
    segment_tree(int n, vi &data){
        nodes.resize(4 * n + 1);
        build(0, n, data);
    }

    void build(int left, int right, vi &data, int pos = 1){
        if(left == right){
            nodes[pos] = node(left ? data[left - 1] : 0);
            return;
        }
        int mid = left + (right - left) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lz(int lz, int pos){
        nodes[pos].lazy += lz;
    }

    void apply_lz(int pos){
        nodes[pos].mini += nodes[pos].lazy;
        nodes[pos].lazy = 0;
    }

    void push_lz(int pos, int left, int right){
        int len = right - left + 1;
        if(1 < len){
            combine_lz(nodes[pos].lazy, pos * 2);
            combine_lz(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lz(pos);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lz(x, pos);
            push_lz(pos, left, right);
            return;
        }
        int mid = (left +  right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    vi arr(q), compress;
    for(int &x : arr){
        cin >> x;
        if(x > 0) compress.pb(x);
    }
    
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    auto idx = [&](int x){return lower_bound(all(compress), x) - compress.begin();};

    int N = sz(compress);
    segment_tree ST(N, compress);
    for(int i = 0; i < q; ++i){
        int x = arr[i];
        if(x > 0){
            ST.update(1, 0, idx(x), 0, N);
        } else {
            x = -x;
            ST.update(-1, 0, idx(x), 0, N);
        }

        cout << ST.query(0, N, 0, N).mini << " \n"[i + 1 == q];
    }
}