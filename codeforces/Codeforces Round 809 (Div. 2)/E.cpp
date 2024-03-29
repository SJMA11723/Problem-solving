/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 300'000
#define LOGN 18
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

struct dsu{
    int RA[MAXN], P[MAXN], depth[MAXN];
    vector<int> KRT[MAXN];
    int P_LCA[LOGN + 1][MAXN];
    int KRT_root = 0;

    dsu(int n){
        for(int i = 0; i < n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    int root(int x){
        if(x == P[x]) return x;
        return P[x] = root(P[x]);
    }

    void join(int x, int y, int w){
        x = root(x);
        y = root(y);
        if(x == y) return;
        KRT_root = w;
        P[x] = w;
        P[y] = w;
        KRT[w].push_back(x);
        KRT[w].push_back(y);
    }

    void precalc(int node, int p = 0, int d = 1){
        depth[node] = d;
        P_LCA[0][node] = p;
        for(int k = 1; k <= LOGN; ++k)
            P_LCA[k][node] = P_LCA[k - 1][P_LCA[k - 1][node]];
        for(int v : KRT[node]) precalc(v, node, d + 1);
    }

    int lca(int a, int b){
        if(depth[b] < depth[a]) swap(a, b);

        int dif = depth[b] - depth[a];
        for(int k = LOGN; 0 <= k; --k)
            if(is_on(dif, k)) b = P_LCA[k][b];

        if(a == b) return a;

        for(int k = LOGN; 0 <= k; --k){
            if(P_LCA[k][a] != P_LCA[k][b]){
                a = P_LCA[k][a];
                b = P_LCA[k][b];
            }
        }
        return P_LCA[0][a];
    }
};

struct sparse_table{
    int n, NEUTRO;
    int ST[LOGN + 1][MAXN / 2], lg2[LOGN + 1];
    int f(int a, int b){return max(a, b);}

    sparse_table(int _n, int data[]){
        n = _n;
        NEUTRO = 0;
        lg2[1] = 0;
        for(int i = 2; i <= n; ++i) lg2[i] = lg2[i / 2] + 1;

        for(int i = 0; i < n; ++i) ST[0][i] = data[i];
        for(int k = 1; k <= lg2[n]; ++k){
            int fin = (1 << k) - 1;
            for(int i = 0; i + fin < n; ++i)
                ST[k][i] = f(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
        }
    }

    int query(int l, int r){
        if(l > r) return NEUTRO;
        int lg = lg2[r - l + 1];
        return f(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, q; cin >> n >> m >> q;
        dsu mset(n + m);
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            mset.join(a, b, i + n);
        }

        mset.precalc(mset.KRT_root, mset.KRT_root);

        int lcas[n - 1];
        for(int i = 0; i + 1 < n; ++i)
            lcas[i] = mset.lca(i, i + 1) + 1 - n;

        sparse_table ST(n - 1, lcas);

        while(q--){
            int l, r; cin >> l >> r;
            l--, r--;
            int ans = 0;
            cout << ST.query(l, r - 1);
            if(q) cout << ' ';
        }
        cout << '\n';
    }

}
