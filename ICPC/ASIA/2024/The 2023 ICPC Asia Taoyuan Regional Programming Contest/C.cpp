#include <bits/stdc++.h>

using namespace std;

struct segment_tree{
    struct node{
        int on, off;
        char lazy;
        node(): on(0), off(0), lazy(0){}
        node(int a, int b, char c) : on(a), off(b), lazy(c){}
        const node operator+(const node &b)const{
            return node(on + b.on, off + b.off, 0);
        }
    };
    vector<node> nodes;
    segment_tree(int n, short data[]){
        nodes.resize(4 * n + 1);
        build(0, n - 1, data);
    }

    void build(int left, int right, short data[], int pos = 1){
        if(left == right){
            if(data[left] == 1) nodes[pos].on++;
            else if(data[left] == 0) nodes[pos].off++;
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lazy(char lz, int pos){
        nodes[pos].lazy ^= lz;
    }

    void apply_lazy(int pos){
        if(nodes[pos].lazy) swap(nodes[pos].on, nodes[pos].off);
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
        int len = abs(right - left) + 1;
        if(1 < len){
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

        int mid = (left + right) / 2;
        update(l, r, left, mid, pos * 2);
        update(l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
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
    int n, m; cin >> n >> m;
    int64_t ans = 0;
    short arr[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> arr[i] >> x;
        ans += x;
    }
    segment_tree seg_tree(n, arr);

    while(m--){
        char c; cin >> c;
        if(c == 'W'){
            int l, r; cin >> l >> r;
            seg_tree.update(l, r, 0, n - 1);
        } else {
            int x; cin >> x;
            ans += 1ll * x * seg_tree.query(0, n - 1, 0, n - 1).on;
        }
    }
    cout << ans << '\n';
}
