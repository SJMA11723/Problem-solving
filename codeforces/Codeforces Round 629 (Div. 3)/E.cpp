/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define LOGN 18
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

void precalc(int u, vector<int> tree[], int depth[], vector<vector<int>> &P, int p = 0){
    depth[u] = depth[p] + 1;
    P[0][u] = p;
    for(int k = 1; k <= LOGN; ++k)
        P[k][u] = P[k - 1][P[k - 1][u]];

    for(int v : tree[u])
        if(v != p) precalc(v, tree, depth, P, u);
}

int LCA(int a, int b, int depth[], vector<vector<int>> &P){
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
    int n, m; cin >> n >> m;
    vector<int> tree[n + 1];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int depth[n + 1]; depth[0] = 1;
    vector<vector<int>> P(LOGN + 1, vector<int>(n + 1));
    precalc(1, tree, depth, P);

    while(m--){
        int k; cin >> k;
        pair<int, int> arr[k];
        for(int i = 0; i < k; ++i){
            int u; cin >> u;
            arr[i] = {depth[u], u};
        }
        sort(arr, arr + k, greater<pair<int, int>>());

        int lca = arr[0].second;
        bool ok = true;
        for(int i = 1; i < k; ++i){
            lca = LCA(lca, arr[i].second, depth, P);
            if(lca != arr[i].second){
                if(P[0][arr[i].second] != lca){
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
