/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct treap{
    typedef struct _node{
        long long x;
        int freq, cnt;
        long long p;
        _node *l, *r;
        _node(long long _x): x(_x), p(((long long)(rand()) << 32 )^rand()),
        cnt(1), freq(1), l(nullptr), r(nullptr){}
        ~_node(){delete l; delete r;}
        void recalc(){
            cnt = freq;
            cnt += ((l) ? (l->cnt) : 0);
            cnt += ((r) ? (r->cnt) : 0);
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
    void split_by_value(node n, long long d, node &l, node &r){
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
    void insert_value(long long x){
        node l, m, r;
        split_by_value(root, x, l, m);
        split_by_value(m, x + 1, m, r);
        if(m){
            m->freq++;
            m->cnt++;
        } else m = new _node(x);
        root = merge(merge(l, m), r);
    }

    int64_t greater(int x){
        node l, r;
        split_by_value(root, x + 1, l, r);
        int ans = r ? r->cnt : 0;
        root = merge(l, r);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> arr[n];
        for(int i = 0; i < n; ++i){
            int a, b; cin >> a >> b;
            arr[i] = {a, b};
        }
        sort(arr, arr + n);

        treap mset;
        int64_t ans = 0;
        for(int i = 0; i < n; ++i){
            ans += mset.greater(arr[i].second);
            mset.insert_value(arr[i].second);
        }
        cout << ans << '\n';
    }
}
