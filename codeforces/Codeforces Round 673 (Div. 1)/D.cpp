/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200'000

using namespace std;

struct edge{
    int from, to;
};

struct dsu{
    int P[2 * MAXN], t_in[2 * MAXN], t_out[2 * MAXN];
    bool vis[2 * MAXN];
    vector<int> tree[2 * MAXN];
    int data[2 * MAXN], n, next_edge;

    dsu(int _n, int arr[]){
        memset(vis, 0, sizeof(vis));
        memset(data, 0, sizeof(data));
        n = _n;
        for(int i = 0; i < n; ++i) data[i] = arr[i];
        for(int i = 0; i < 2 * n; ++i) P[i] = i;
        next_edge = n;
    }

    int root(int x){
        if(x == P[x]) return x;
        return P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        P[x] = next_edge;
        P[y] = next_edge;
        tree[next_edge].push_back(x);
        tree[next_edge].push_back(y);
        next_edge++;
    }

    void dfs(int node, vector<int> &arr){
        if(vis[node]) return;
        vis[node] = true;
        t_in[node] = arr.size();
        if(tree[node].empty()) arr.push_back(data[node]);
        for(int v : tree[node]) dfs(v, arr);
        t_out[node] = (int)arr.size() - 1;
    }
};

struct segment_tree{
    struct node{
        int val, idx;
        node():val(0), idx(-1){};
        node(int x, int _idx):val(x), idx(_idx){}
        node operator+(const node &b)const{
            if(val < b.val) return b;
            return node(val, idx);
        }
    };
    vector<node> nodes;
    segment_tree(int n, vector<int> &data){
        nodes.resize(4 * n + 1);
        build(0, n - 1, data);
    }

    void build(int left, int right, vector<int> &data, int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left], left);
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
            nodes[pos].val = x;
            return;
        }
        int mid = (left + right) / 2;
        update(x, idx, left, mid, pos * 2);
        update(x, idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int arr[n];
    for(int &p : arr) cin >> p;

    vector<edge> edges(m);
    for(edge &e : edges){
        cin >> e.from >> e.to;
        e.from--, e.to--;
    }

    bool erased[m] = {};
    pair<int, int> queries[q];
    for(pair<int, int> &p : queries){
        cin >> p.first >> p.second;
        p.second--;
        if(p.first == 2) erased[p.second] = true;
    }

    dsu mset(n, arr);
    for(int i = 0; i < m; ++i){
        if(erased[i]) continue;
        mset.join(edges[i].from, edges[i].to);
    }

    int q_root[q];
    for(int i = q - 1; 0 <= i; --i){
        auto [t, idx] = queries[i];
        if(t == 1) q_root[i] = mset.root(idx);
        else mset.join(edges[idx].from, edges[idx].to);
    }

    vector<int> nums;
    for(int i = 0; i < n; ++i){
        mset.dfs(mset.root(i), nums);
    }

    /*for(int v : nums) cout << v << ' ';
    cout << '\n';*/

    segment_tree seg_tree(nums.size(), nums);
    for(int i = 0; i < q; ++i){
        int t = queries[i].first;
        if(t == 1){
            //cout << "Range: [" << q_root[i] << "] " << mset.t_in[q_root[i]] << ' ' << mset.t_out[q_root[i]] << '\n';
            auto [val, idx] = seg_tree.query(mset.t_in[q_root[i]], mset.t_out[q_root[i]], 0, nums.size() - 1);
            seg_tree.update(0, idx, 0, nums.size() - 1);
            cout << val << '\n';
            /*for(int j = 0; j < nums.size(); ++j)
                cout << seg_tree.query(j, j, 0, nums.size() - 1).val << ' ';
            cout << '\n';*/
        }
    }
}
