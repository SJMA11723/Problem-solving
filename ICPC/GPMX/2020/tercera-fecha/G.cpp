#include<bits/stdc++.h>
using namespace std;

struct segment_tree{
    struct node{
        int val;
        node():val(0){}
        node(int x):val(x){}
        const node operator+(const node &b)const{
            return node(max(val, b.val));
        }
    };
    vector<node> nodes;

    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(0, n - 1, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void update(int x, int idx, int left, int right, int pos = 1){
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

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    int ans[2 * n] = {};

    segment_tree seg_tree(2 * n, ans);

    int g[n], a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> g[i] >> a[i] >> b[i];

    for(int i = n - 1; 0 <= i; --i){
        ans[i] = g[i] + seg_tree.query(i + a[i], i + b[i], 0, 2 * n - 1).val;
        seg_tree.update(ans[i], i, 0, 2 * n - 1);
    }

    cout << *max_element(ans, ans + n) << '\n';

    return 0;
}
