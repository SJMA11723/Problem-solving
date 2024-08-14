/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct segment_tree{
    struct node{
        int val, val_1;
        bool lazy;
        node():val(0), val_1(0), lazy(0){}
        node(int x, char c, int lz = 0): val(x), val_1(x * (c - '0')), lazy(lz){}
        node(int x, int x1, int lz = 0): val(x), val_1(x1), lazy(lz){}
        const node operator+(const node &b)const{
            return node(val ^ b.val, val_1 ^ b.val_1);
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[], string &s){
        nodes.resize(4 * n + 1);
        build(1, n, data, s);
    }

    void build(int left, int right, int data[], string &s, int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left], s[left]);
            //cout << data[left] << ' ' << s[left] << ' ' << nodes[pos].val << ' ' << nodes[pos].val_1 << '\n';
            return;
        }
        int mid = left + (right - left) / 2;
        build(left, mid, data, s, pos * 2);
        build(mid + 1, right, data, s, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lazy(bool lz, int pos){nodes[pos].lazy ^= lz;}

    void apply_lazy(int pos){
        nodes[pos].val_1 ^= nodes[pos].val * nodes[pos].lazy;
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
        int tam = right - left + 1;
        if(1 < tam){
            combine_lazy(nodes[pos].lazy, pos * 2);
            combine_lazy(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lazy(pos);
    }

    void update(int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lazy(1, pos);
            push_lazy(pos, left, right);
            return;
        }

        int mid = left + (right - left) / 2;
        update(l, r, left, mid, pos * 2);
        update(l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = left + (right - left) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n + 1];
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        string s(n + 1, '0');
        for(int i = 1; i <= n; ++i) cin >> s[i];
        segment_tree seg_tree(n, arr, s);

        int q; cin >> q;
        while(q--){
            int type; cin >> type;
            if(type == 1){
                int l, r; cin >> l >> r;
                seg_tree.update(l, r, 1, n);
            } else {
                short g; cin >> g;
                auto Q = seg_tree.query(1, n, 1, n);
                if(g) cout << Q.val_1 << ' ';
                else cout << (Q.val ^ Q.val_1) << ' ';
            }
        }
        cout << '\n';
    }
}
