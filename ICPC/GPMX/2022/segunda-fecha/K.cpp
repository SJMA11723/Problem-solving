#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

struct nodo{
    int left, right;
    long long sum;
    long long sumSQ;
    long long lazy;
};

struct SegmentTree{
    int n;
    long long *arr;
    nodo *nodos;

    SegmentTree(int sz){
        n = sz;
        arr = new long long[n + 1];
        nodos = new nodo[4*n + 1];
    }

    void scanValues(){
        for(int i = 1; i <= n; ++i)
            cin >> arr[i];
    }

    void build(int l, int r, int pos = 1){
        nodos[pos].lazy = 0;

        nodos[pos].left = l;
        nodos[pos].right = r;

        if(nodos[pos].left == nodos[pos].right){
            nodos[pos].sum = arr[r];
            nodos[pos].sumSQ = arr[r] * arr[r] % MOD;
            return;
        }

        int mitad = (nodos[pos].left + nodos[pos].right) / 2;

        build(l, mitad, pos * 2);
        build(mitad + 1, r, pos * 2 + 1);

        nodos[pos].sum = (nodos[pos * 2].sum + nodos[pos * 2 + 1].sum) % MOD;
        nodos[pos].sumSQ = (nodos[pos * 2].sumSQ + nodos[pos * 2 + 1].sumSQ) % MOD;
    }

    void pushLazy(int pos){
        ///izq
        long long left = nodos[pos].left,
            right = nodos[pos].right,
            tam = abs(right - left + 1);

        if(1 < tam){
            nodos[pos * 2].lazy += nodos[pos].lazy;
            nodos[pos * 2].lazy %= MOD;

            nodos[pos * 2 + 1].lazy += nodos[pos].lazy;
            nodos[pos * 2 + 1].lazy %= MOD;
        }

        /// sumo tam*b^2 + 2b(a1+a2+..+an) | a^2 -> (a + b)^2 = a^2 + 2ab + b^2
        long long b = nodos[pos].lazy;
        nodos[pos].sumSQ += b * b % MOD * tam % MOD + 2 * b * nodos[pos].sum % MOD;
        nodos[pos].sumSQ %= MOD;

        nodos[pos].sum += b * tam % MOD;
        nodos[pos].sum %= MOD;

        nodos[pos].lazy = 0;
    }

    void update(long long x, int left, int right, int pos = 1){
        pushLazy(pos);

        if(right < nodos[pos].left || nodos[pos].right < left) return;

        if(left <= nodos[pos].left && nodos[pos].right <= right){
            nodos[pos].lazy += x + MOD;
            nodos[pos].lazy %= MOD;
            pushLazy(pos);
            return;
        }

        update(x, left, right, pos * 2);
        update(x, left, right, pos * 2 + 1);

        nodos[pos].sum = (nodos[pos * 2].sum + nodos[pos * 2 + 1].sum) % MOD;
        nodos[pos].sumSQ = (nodos[pos * 2].sumSQ + nodos[pos * 2 + 1].sumSQ) % MOD;
    }

    long long sumQ(int left, int right, int pos = 1){
        pushLazy(pos);

        if(right < nodos[pos].left || nodos[pos].right < left) return 0;

        if(left <= nodos[pos].left && nodos[pos].right <= right)
            return nodos[pos].sumSQ;

        return (sumQ(left, right, pos * 2) + sumQ(left, right, pos * 2 + 1)) % MOD;
    }

    ~SegmentTree(){
        delete[] nodos;
        delete[] arr;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    SegmentTree seg(n);

    seg.scanValues();
    seg.build(1, n);

    while(q--){
        int a, b;
        long long x;
        char c;
        cin >> c >> a >> b;
        if(c == 'u'){
            cin >> x;
            seg.update(x, a, b);
        } else cout << seg.sumQ(a, b) << '\n';
    }

}