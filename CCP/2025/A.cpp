#include <bits/stdc++.h>

#define lsb(n) ((n) & (-n))

using namespace std;

struct segment_tree{
    struct node{
        int val;
        char first, last;
        node():val(0){
            first = last = 0;
        }
        node(char c):val(1){
            first = last = c;
        }
        const node operator+(const node &b){
            node res(0);
            if(!val){
                res = b;
                return res;
            }
            if(!b.val){
                return *this;
            }
            res.val = val + b.val;
            if(last == b.first) res.val--;
            res.first = first;
            res.last = b.last;
            return res;
        }
    };
    vector<node> nodes;
    string str;
    segment_tree(int n, string &data){
        nodes.resize(4 * n + 1);
        str = data;
        build(1, n, data);
    }

    void build(int left, int right, string &data, int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void update(char x, int idx, int left, int right, int pos = 1){
        if(idx < left || right < idx) return;
        if(left == right){
            nodes[pos] = node(x);
            return;
        }
        int mid = (left + right) / 2;
        update(x, idx, left, mid, pos * 2);
        update(x, idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
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
    int n, q; cin >> n >> q;
    string str; cin >> str;
    str = "#" + str;
    
    segment_tree ST(n, str);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            cout << ST.query(l, r, 1, n).val << '\n';
        } else {
            int p;
            char c;
            cin >> p >> c;
            ST.update(c, p, 1, n);
        }
    }
}