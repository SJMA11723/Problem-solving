#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define LOGN 18

using namespace std;

vector<int> depth;
vector<vector<int>> P;

void precalc(int u, vector<int> tree[], int p = 0, int d = 1){
    depth[u] = d;
    P[0][u] = p;
    for(int k = 1; k <= LOGN; ++k){
        P[k][u] = P[k - 1][P[k - 1][u]];
    }
    for(int v : tree[u])
    if(v != p) precalc(v, tree, u, d + 1);
}

int LCA(int a, int b){
    if(depth[b] < depth[a]) swap(a, b);
    int diff = depth[b] - depth[a];
    for(int k = LOGN; 0 <= k; --k){
        if(is_on(diff, k)) b = P[k][b];
    }
    if(a == b) return a;

    for(int k = LOGN; 0 <= k; --k){
        if(P[k][a] != P[k][b]){
            a = P[k][a];
            b = P[k][b];
        }
    }
    return P[0][a];
}

int cnt_comp = 0;

void dfs(int u, vector<int> tree[], char vis[], int &node, int &maxd, int d = 1, int p = 0){
    if(maxd < d){
        maxd = d;
        node = u;
    }

    //cout << "Llega " << u << endl;
    vis[u] = cnt_comp;
    for(int v : tree[u])
        if(v != p){
            //cout << "Intenta " << v << endl;
            dfs(v, tree, vis, node, maxd, d + 1, u);
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;

    depth.resize(n + 1);
    P.resize(LOGN + 1, vector<int>(n + 1));
    vector<int> forest[n + 1];
    for(int i = 3; i < n; ++i){
        int a, b; cin >> a >> b;
        forest[a].push_back(b);
        forest[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(depth[i]) continue;
        precalc(i, forest);
    }

    char vis[n + 1] = {};

    int l[4], r[4], d[4];
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        cnt_comp++;
        int curl = i, curr, maxd = 0;

        //cout << curl << endl;

        dfs(curl, forest, vis, curr, maxd);

        maxd = 0;
        dfs(curr, forest, vis, curl, maxd);

        l[cnt_comp] = curl;
        r[cnt_comp] = curr;
        d[cnt_comp] = maxd;
    }

    while(q--){
        int a, b; cin >> a >> b;
        bool ap[4] = {};
        char comp1 = vis[a], comp2 = vis[b], comp3;
        ap[comp1] = ap[comp2] = 1;
        for(int i = 1; i <= 3; ++i)
        if(!ap[i]) comp3 = i;

        int ans = d[comp3];

        int lca1 = LCA(l[comp1], a);
        int lca2 = LCA(r[comp1], a);
        ans += max(depth[a] + depth[l[comp1]] - 2 * depth[lca1] + 1,
                   depth[a] + depth[r[comp1]] - 2 * depth[lca2] + 1);

        lca1 = LCA(l[comp2], b);
        lca2 = LCA(r[comp2], b);
        ans += max(depth[b] + depth[l[comp2]] - 2 * depth[lca1] + 1,
                   depth[b] + depth[r[comp2]] - 2 * depth[lca2] + 1);

        cout << ans << '\n';
    }
}
