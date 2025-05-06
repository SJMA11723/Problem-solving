
#include<bits/stdc++.h>

using namespace std;

vector<int> subtree_size;
vector<int> vals, depth, ans;
vector<bool> big;
vector<vector<int>> tree;
vector< vector<pair<int, int>> > queries;

void precalc(int node, int p = 0){
    subtree_size[node] = 1;
    depth[node] = depth[p] + 1;
    for(int v : tree[node]){
        if(v == p) continue;
        precalc(v, node);
        subtree_size[node] += subtree_size[v];
    }
}

map<int, int> cnt;

void add(int node, int x, int p = 0){
    cnt[vals[node]] += x;

    for(int v : tree[node]){
        if(v != p && !big[v]){
            add(v, x, node);
        }
    }
}

void dfs(int node, bool keep, int p = 0){
    int maxi = -1, big_child = -1;
    for(int v : tree[node]){
        if(v != p && subtree_size[v] > maxi){
            maxi = subtree_size[v];
            big_child = v;
        }
    }

    for(int v : tree[node]){
        if(v != p && v != big_child){
            dfs(v, false, node);
        }
    }

    if(big_child != -1){
        dfs(big_child, true, node);
        big[big_child] = 1;
    }
    add(node, 1, p);

    /// responde preguntas aqui
    for(pair<int, int> &q : queries[node]){
        int k, idx;
        tie(k, idx) = q;
        ans[idx] = cnt[k];
    }

    if(big_child != -1) big[big_child] = 0;
    if(!keep) add(node, -1, p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    subtree_size.resize(n + 1);
    depth.resize(n + 1);
    vals.resize(n + 1);
    tree.resize(n + 1);
    big.resize(n + 1);

    for(int i = 1; i <= n; ++i) cin >> vals[i];

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
    }

    precalc(1);

    queries.resize(n + 1);
    ans.resize(q);
    for(int i = 0; i < q; ++i){
        int x, k;
        cin >> x >> k;
        queries[x].push_back({k, i});
    }

    dfs(1, true);

    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
}

/**
    Imprime 0 0 0 1
*/


