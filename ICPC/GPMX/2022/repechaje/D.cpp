#include <bits/stdc++.h>

using namespace std;

class Treap{
private:
    typedef struct _Node{
        long long x, p;
        int freq, cnt;
        _Node *l, *r;

        _Node(long long _x): x(_x), p(((long long)(rand()) << 32 )^rand()), cnt(1), freq(1), l(nullptr), r(nullptr){}

        ~_Node(){delete l; delete r;}

        void recalc(){
            cnt = freq;
            cnt += ((l) ? (l->cnt) : 0);
            cnt += ((r) ? (r->cnt) : 0);
        }
    }* Node;

    Node root;

    Node merge(Node l, Node r){
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

    void splitByValue(Node n, const long long d, Node &l, Node &r){
        l = r = nullptr;
        if(!n) return;

        if(n->x < d){
            splitByValue(n->r, d, n->r, r);
            l = n;
        } else {
            splitByValue(n->l, d, l, n->l);
            r = n;
        }
        n->recalc();
    }

public:
    Treap(): root(NULL){}

    void insertOrderedByValue(const long long x){
        Node l, m, r;
        splitByValue(root, x, l, m);
        splitByValue(m, x + 1, m, r);

        if(m){
            m->freq++;
            m->cnt++;
        } else m = new _Node(x);

        root = merge(merge(l, m), r);
    }

    void eraseByValue(const long long x){
        Node l, m, r;
        splitByValue(root, x, l, m);
        splitByValue(m, x + 1, m, r);

        if(!m || m->freq == 1){
            delete m;
            m = nullptr;
        } else {
            m->freq--;
            m->cnt--;
        }

        root = merge(merge(l, m), r);
    }

    int smaller(const long long x){
        Node l, r;
        splitByValue(root, x, l, r);
        int res = l ? l->cnt : 0;
        root = merge(l, r);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Treap arr;

    int q; cin >> q;
    long long added[100005] = {};

    for(int i = 1; i <= q; ++i){
        int t; cin >> t;
        if(t == 1){
            long long x; cin >> x;
            arr.insertOrderedByValue(x);
            added[i] = x;
        } else if(t == 2){
            int p; cin >> p;
            arr.eraseByValue(added[p]);
        } else if(t == 3){
            long long k;
            int p;
            cin >> p >> k;
            arr.eraseByValue(added[p]);
            added[p] += k;
            arr.insertOrderedByValue(added[p]);
        } else if(t == 4){
            int p;
            cin >> p;
            cout << arr.smaller(added[p]) << '\n';
        }
    }
}
