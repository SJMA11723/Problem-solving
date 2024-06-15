/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;


struct segment_tree{
    struct node{
        int menor, cero, mayor;
        node():menor(0), cero(0), mayor(0){}/// inicializa con el neutro
        node(int a, int b, int c):menor(a), cero(b), mayor(c){}
        node(int x){
            menor = cero = mayor = 0;
            if(x < 0) menor++;
            else if(x > 0) mayor++;
            else cero++;
        }
        const node operator+(const node &b)const{
            return node(menor + b.menor, cero + b.cero, mayor + b.mayor);
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
    int n, q; cin >> n >> q;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    segment_tree seg_tree(n, arr);

    while(q--){
        char c; cin >> c;
        if(c == 'C'){
            int idx, v; cin >> idx >> v;
            seg_tree.update(v, idx, 1, n);
        } else {
            int a, b; cin >> a >> b;
            if(a > b) swap(a, b);
            auto node = seg_tree.query(a, b, 1, n);
            if(node.cero) cout << "0\n";
            else if(node.menor % 2) cout << "-\n";
            else cout << "+\n";
        }
    }
}
