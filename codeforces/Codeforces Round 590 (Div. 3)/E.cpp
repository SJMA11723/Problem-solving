/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct segment_tree{
    struct node{
        int64_t val, lazy;
        node():val(0), lazy(0){}/// inicializa con el neutro y sin lazy pendiente
        node(int64_t x, int64_t lz = 0):val(x), lazy(lz){}
        const node operator+(const node &b)const{
            return node(val + b.val);
        }
    };
    vector<node> nodes;
    segment_tree(int n){
        nodes.resize(4 * n + 1);
    }

    void combine_lazy(int64_t lz, int pos){
        nodes[pos].lazy += lz;
    }

    /// IMPORTANTE: ESTE UPDATE ES PARA SUMA/RESTA. CAMBIAR SI ES NECESARIO
    void apply_lazy(int pos, int64_t tam){
        nodes[pos].val += nodes[pos].lazy * tam;
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
        int tam = abs(right - left + 1);
        if(1 < tam){
            combine_lazy(nodes[pos].lazy, pos * 2);
            combine_lazy(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lazy(pos, tam);
    }

    void update(int64_t x, int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lazy(x, pos);
            push_lazy(pos, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
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
    int n, m; cin >> n >> m;

    segment_tree seg_tree(n);

    int64_t prv; cin >> prv;
    for(int i = 1; i < m; ++i){
        int64_t x; cin >> x;
        int64_t mini = min(prv, x);
        int64_t maxi = max(prv, x);

        if(prv == x) continue;

        seg_tree.update(maxi - mini, 1, mini - 1, 1, n);
        seg_tree.update(maxi - mini, maxi + 1, n, 1, n);
        seg_tree.update(maxi - 1, mini, mini, 1, n);
        seg_tree.update(mini, maxi, maxi, 1, n);
        seg_tree.update(maxi - mini - 1, mini + 1, maxi - 1, 1, n);
        prv = x;
    }

    for(int i = 1; i <= n; ++i) cout << seg_tree.query(i, i, 1, n).val << " \n"[i == n];
}
