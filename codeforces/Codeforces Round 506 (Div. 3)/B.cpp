/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct segment_tree{
    struct node{
        int val;
        node():val(0){}/// inicializa con el neutro
        node(int x):val(x){}
        const node operator+(const node &b)const{
            return node(max(val, b.val));
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos].val = data[left];
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
            nodes[pos].val += x;
            return;
        }
        int mid = (left + right) / 2;
        update(x, idx, left, mid, pos * 2);
        update(x, idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return node(); /// Devuelve el neutro
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    int maxi[n + 1] = {};
    int ans = 0;
    segment_tree seg_tree(n, maxi);

    for(int i = 1; i <= n; ++i){
        int pos = lower_bound(arr + 1, arr + i, (arr[i] + 1) / 2) - arr;
        int max_seq = seg_tree.query(pos, i, 1, n).val;
        ans = max(ans, max_seq + 1);
        seg_tree.update(max_seq + 1, i, 1, n);
    }

    cout << ans << '\n';
}
