/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct interval{
    int l, r;
    int idx;

    bool operator<(const interval &b){
        return make_pair(l, r) < make_pair(b.l, b.r);
    }

    bool operator>(const interval &b)const{
        return make_pair(r, l) < make_pair(b.r, b.l);
    }
};

struct segmet_tree{
    struct node{
        int64_t maxi, mini, lazy;
        node(): maxi(LLONG_MIN), mini(LLONG_MAX), lazy(0){}
        node(int64_t M, int64_t m, int64_t lz = 0): maxi(M), mini(m), lazy(lz){}
        const node operator+(const node &b)const{
            return node(max(maxi, b.maxi), min(mini, b.mini));
        }
    };
    vector<node> nodes;
    segmet_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left], data[left]);
            return;
        }

        int mid = left + (right - left) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lazy(int64_t lz, int pos){nodes[pos].lazy += lz;}

    void apply_lazy(int pos, int tam){
        nodes[pos].mini += nodes[pos].lazy;
        nodes[pos].maxi += nodes[pos].lazy;
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
        int tam = right - left + 1;
        if(1 < tam){
            combine_lazy(nodes[pos].lazy, pos * 2);
            combine_lazy(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lazy(pos, tam);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lazy(x, pos);
            push_lazy(pos, left, right);
            return;
        }

        int mid = left + (right - left) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
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
    int n, m; cin >> n >> m;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    segmet_tree seg_tree(n, arr);
    interval ints[m], ints_r[m];
    for(int i = 0; i < m; ++i){
        int l, r; cin >> l >> r;
        ints[i] = {l, r, i + 1};
        ints_r[i] = {l, r, i + 1};

        seg_tree.update(-1, l, r, 1, n);
    }
    sort(ints, ints + m);
    sort(ints_r, ints_r + m, greater<interval>());

    int64_t diff = -1;
    int ans_l = 0, ans_r = 0;
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++i){
        while(l < m && ints_r[l].r < i){
            seg_tree.update(-1, ints_r[l].l, ints_r[l].r, 1, n);
            l++;
        }

        while(r < m && ints[r].l <= i){
            seg_tree.update(1, ints[r].l, ints[r].r, 1, n);
            r++;
        }

        auto q = seg_tree.query(1, n, 1, n);
        if(diff < q.maxi - q.mini){
            diff = q.maxi - q.mini;
            ans_l = l;
            ans_r = r;
        }
    }

    cout << diff << '\n' << ans_l + m - ans_r << '\n';
    for(int i = 0; i < ans_l; ++i) cout << ints_r[i].idx << ' ';
    for(int i = ans_r; i < m; ++i) cout << ints[i].idx << ' ';
    cout << '\n';
}
