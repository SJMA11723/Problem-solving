/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct treap{
    typedef struct _node{
        long long x, c, sum;
        long long p;
        _node *l, *r;
        _node(long long _x, long long _c): x(_x), p(((long long)(rand()) << 32 )^rand()),
        sum(_c), c(_c), l(nullptr), r(nullptr){}
        ~_node(){delete l; delete r;}
        void recalc(){
            sum = c;
            sum += ((l) ? (l->sum) : 0);
            sum += ((r) ? (r->sum) : 0);
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
    void insert_value(long long x, long long c){
        node l, m, r;
        split_by_value(root, x, l, m);
        split_by_value(m, x + 1, m, r);
        if(m){
            m->c += c;
            m->recalc();
        } else m = new _node(x, c);
        root = merge(merge(l, m), r);
    }
    long long sum_smaller(long long x){
        node l, r;
        split_by_value(root, x, l, r);
        long long res = l ? l->sum : 0;
        root = merge(l, r);
        return res;
    }
};

struct point{
    int x, y;
    long long c;
    bool operator<(const point &b){
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<point> arr;
        arr.reserve(n + m);
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            arr.push_back({x, y, 0});
        }

        for(int i = 0; i < m; ++i){
            long long c;
            int x, y;
            cin >> x >> y >> c;
            arr.push_back({y, x, c});
        }

        sort(arr.begin(), arr.end());

        treap m_set;

        long long ans = 0;
        for(point &p : arr){
            if(p.c == 0) ans = max(ans, m_set.sum_smaller(p.y + 1));
            else m_set.insert_value(p.y, p.c);
        }
        cout << ans << '\n';
    }
}
