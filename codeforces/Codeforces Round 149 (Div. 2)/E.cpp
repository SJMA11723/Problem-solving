/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

struct segment_tree{
    struct node{
        int64_t val, lazy;
        int64_t cub[21];


        node():val(0), lazy(0){
            memset(cub, 0, sizeof(cub));
        }/// inicializa con el neutro y sin lazy pendiente



        node(int x):val(x), lazy(0){
            memset(cub, 0, sizeof(cub));
            for(int i = 0; i < 21; ++i)
                if(is_on(x, i)) cub[i]++;
        }


        const node operator+(const node &b)const{
            node res;
            res.val = val + b.val;
            for(int i = 0; i < 21; ++i)
                res.cub[i] = cub[i] + b.cub[i];

            return res;
        }
    }nodes[4 * MAXN + 1];

    segment_tree(int n, int data[]){
        build(1, n, data);
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

    void combineLazy(int lz, int pos){
        nodes[pos].lazy ^= lz;
        /// (x_2 xor x) xor a_i
    }

    void applyLazy(int pos, int64_t tam){
        nodes[pos].val = 0;
        for(int i = 0; i < 21; ++i){
            if(is_on(nodes[pos].lazy, i))
                nodes[pos].cub[i] = tam - nodes[pos].cub[i];

            nodes[pos].val += nodes[pos].cub[i] * (1ll << i);
        }

        nodes[pos].lazy = 0;
    }

    void pushLazy(int pos, int left, int right){
        int tam = abs(right - left + 1);
        if(1 < tam){
            combineLazy(nodes[pos].lazy, pos * 2);
            combineLazy(nodes[pos].lazy, pos * 2 + 1);
        }
        applyLazy(pos, tam);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        pushLazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combineLazy(x, pos);
            pushLazy(pos, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);


        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        pushLazy(pos, left, right);
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
    segment_tree seg_tree(n, arr);

    int m; cin >> m;
    while(m--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            cout << seg_tree.query(l, r, 1, n).val << '\n';
        } else {
            int x; cin >> x;
            seg_tree.update(x, l, r, 1, n);
        }
    }
}
