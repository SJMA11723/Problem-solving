/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree{
    struct nodo{
        int val, lazy;
        nodo():val(0), lazy(0){}/// inicializa con el neutro y sin lazy pendiente
        nodo(int x, int lz = 0):val(x), lazy(lz){}
        const nodo operator+(const nodo &b)const{
            return nodo(val + b.val);
        }
    }*nodos;
    int *arr;
    SegmentTree(int n){
        arr = new int[n + 1];
        nodos = new nodo[4 * n + 1];
    }

    void combineLazy(int lz, int pos){
        nodos[pos].lazy += lz;
    }

    /// IMPORTANTE: ESTE UPDATE ES PARA SUMA/RESTA. CAMBIAR SI ES NECESARIO
    void applyLazy(int pos, int tam){
        nodos[pos].val += nodos[pos].lazy * tam;
        nodos[pos].lazy = 0;
    }

    void pushLazy(int pos, int left, int right){
        int tam = abs(right - left + 1);
        if(1 < tam){
            combineLazy(nodos[pos].lazy, pos * 2);
            combineLazy(nodos[pos].lazy, pos * 2 + 1);
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

        int mitad = (left + right) / 2;
        update(x, l, r, left, mitad, pos * 2);
        update(x, l, r, mitad + 1, right, pos * 2 + 1);

        nodos[pos] = nodos[pos * 2] + nodos[pos * 2 + 1];
    }

    nodo query(int l, int r, int left, int right, int pos = 1){
        pushLazy(pos, left, right);
        if(r < left || right < l) return nodo(0); /// Devuelve el neutro
        if(l <= left && right <= r) return nodos[pos];
        int mitad = (left + right) / 2;
        return query(l, r, left, mitad, pos * 2) + query(l, r, mitad + 1, right, pos * 2 + 1);
    }

    ~SegmentTree(){
        delete[] nodos;
        delete[] arr;
    }
};

int sumDigits(int x){
    int suma = 0;
    while(x){
        suma += x % 10;
        x /= 10;
    }
    return suma;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<int> arr[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            arr[i].push_back(x);
            while(9 < x){
                x = sumDigits(x);
                arr[i].push_back(x);
            }
        }

        SegmentTree segTree(n);
        while(q--){
            int t; cin >> t;
            if(t == 1){
                int a, b; cin >> a >> b;
                segTree.update(1, a, b, 1, n);
            } else {
                int x; cin >> x;
                int con = segTree.query(x, x, 1, n).val;
                cout << arr[x - 1][min((int)arr[x - 1].size() - 1, con)] << '\n';
            }
        }
    }
}
