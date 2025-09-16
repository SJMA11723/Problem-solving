#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))
#define LOGN 17

using namespace std;

vector<int> depth;
vector<vector<int>> P;

void precalc(int u, vector<int> tree[], int p = 0, int d = 1){
    depth[u] = d;
    P[0][u] = p;
    for(int k = 1; k <= LOGN; ++k)
        P[k][u] = P[k - 1][P[k - 1][u]];
    for(int v : tree[u])
        if(v != p) precalc(v, tree, u, d + 1);
}

int LCA(int a, int b){
    if(depth[b] < depth[a]) swap(a, b);
    int diff = depth[b] - depth[a];
    for(int k = LOGN; 0 <= k; --k)
        if(is_on(diff, k)) b = P[k][b];
    if(a == b) return a;
    for(int k = LOGN; 0 <= k; --k){
        if(P[k][a] != P[k][b]){
            a = P[k][a];
            b = P[k][b];
        }
    }
    return P[0][a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> tree[n + 1];
    depth.resize(n + 1);
    P.resize(LOGN + 1, vector<int>(n + 1));
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    precalc(1, tree);

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int L1 = LCA(a, b);

        if(LCA(L1, c) != L1 && LCA(L1, d) != L1){
            cout << "0\n";
            continue;
        }

        int L2 = LCA(c, d);
        if(LCA(L2, a) != L2 && LCA(L2, b) != L2){
            cout << "0\n";
            continue;
        }

        int l = LCA(c, a);
        if(depth[l] < depth[LCA(c, b)]) l = LCA(c, b);
        if(depth[l] < depth[L1]) l = L1;

        int r = LCA(d, a);
        if(depth[r] < depth[LCA(d, b)]) r = LCA(d, b);
        if(depth[r] < depth[L1]) r = L1;

        L2 = LCA(l, r);
        cout << depth[l] - depth[L2] + depth[r] - depth[L2] + 1 << '\n';
    }
}