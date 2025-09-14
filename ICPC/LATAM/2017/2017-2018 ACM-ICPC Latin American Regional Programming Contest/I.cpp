#include <bits/stdc++.h>
#define is_on(S, i) ((S) & (1ll << (i)))
#define LOGN 20

using namespace std;

struct dsu{
    vector<int> P, RA;
    dsu(int n){
        P.resize(n);
        RA.resize(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};

struct edge{
    int from, to, w, idx;
    const bool operator<(const edge &b)const{
        return w < b.w;
    }

    edge operator-(){
        return edge{to, from, w, idx};
    }
};

int64_t kruskal(int n, vector<edge> edges, vector<edge> mst[], bool used[]){
    sort(edges.begin(), edges.end());
    dsu mset(n + 1);
    int64_t cost = 0;
    for(edge &e : edges){
        if(mset.join(e.from, e.to)){
            cost += e.w;
            mst[e.from].push_back(e);
            mst[e.to].push_back(-e);
            used[e.idx] = true;
        }
    }
    return cost;
}

vector<int> depth;
vector<vector<int>> P, ST;

void precalc(int node, vector<edge> tree[], int w = 0, int p = 0, int d = 1){
    depth[node] = d;
    P[0][node] = p;
    ST[0][node] = w;
    for(int k = 1; k <= LOGN; ++k){
        P[k][node] = P[k - 1][P[k - 1][node]];
        ST[k][node] = max(ST[k - 1][node], ST[k - 1][P[k - 1][node]]);
    }

    for(edge &e : tree[node])
        if(p != e.to) precalc(e.to, tree, e.w, node, d + 1);
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

int max_nth_ancestor(int a, int n){
    int res = 0;

    for(int k = LOGN; 0 <= k; --k){
        if(is_on(n, k)){
            res = max(res, ST[k][a]);
            a = P[k][a];
        }
    }

    return res;
}

int max_in_path(int a, int b){
    int lca = LCA(a, b);
    return max(max_nth_ancestor(a, depth[a] - depth[lca]),
               max_nth_ancestor(b, depth[b] - depth[lca]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r; cin >> n >> r;

    depth.resize(n + 1, -1);
    P.resize(LOGN + 1, vector<int>(n + 1));
    ST.resize(LOGN + 1, vector<int>(n + 1, -1));

    vector<edge> edges;
    map<pair<int, int>, int> e_indexes;
    for(int i = 0; i < r; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c, i});
        e_indexes[{a, b}] = i;
    }

    bool used_edges[r] = {};
    vector<edge> mst[n + 1];
    int64_t mst_cost = kruskal(n, edges, mst, used_edges);

    precalc(1, mst);

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        int idx = e_indexes[{a, b}];
        if(used_edges[idx]) cout << mst_cost << '\n';
        else cout << mst_cost + edges[idx].w - max_in_path(a, b) << '\n';
    }
}
