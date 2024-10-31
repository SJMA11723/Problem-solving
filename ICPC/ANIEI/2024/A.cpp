#include <bits/stdc++.h>
#define MAXN 100000
#define lsb(n) ((n) & -(n))

using namespace std;

void dfs(int u, vector<int> tree[], vector<int> &euler, int t_in[], int subtree[], int dist[], int p = -1){
    if(p != -1) dist[u] = dist[p] + 1;
    t_in[u] = euler.size();
    euler.push_back(dist[u]);

    subtree[u] = 1;
    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, euler, t_in, subtree, dist, u);
        subtree[u] += subtree[v];
    }
}

const int block_size = 320;

struct query{
    int l, r, k, block, i;
    bool operator<(const query &b)const{
        if(block == b.block) return r < b.r;
        return block < b.block;
    }
};

struct fenwick_tree{
    int n;
    vector<int> BIT;

    fenwick_tree(int _n){
        n = _n;
        BIT.resize(n + 1);
    }

    void add(int pos, int x){
        while(pos <= n){
            BIT[pos] += x;
            pos += lsb(pos);
        }
    }

    int sum(int pos){
        int res = 0;
        while(pos){
            res += BIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }
} BIT(MAXN + 2);

void add(int x){
    BIT.add(x + 1, 1);
}

void remove(int x){
    BIT.add(x + 1, -1);
}

int get_answer(int l, int r){
    return BIT.sum(r + 1) - BIT.sum(l);
}

vector<int> solve(vector<query> &queries, vector<int> &arr){
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    for(query &q : queries){
        while(cur_l > q.l) add(arr[--cur_l]);
        while(cur_r < q.r) add(arr[++cur_r]);
        while(cur_l < q.l) remove(arr[cur_l++]);
        while(cur_r > q.r) remove(arr[cur_r--]);
        answers[q.i] = get_answer(arr[q.l], arr[q.l] + q.k);
    }
    return answers;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int t_in[n] = {}, subtree[n] = {}, dist[n] = {};
    vector<int> euler;
    dfs(0, tree, euler, t_in, subtree, dist);

    vector<query> queries;
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int u, k; cin >> u >> k;
        u--;
        queries.push_back({t_in[u], t_in[u] + subtree[u] - 1, k, t_in[u] / block_size, i});
    }

    vector<int> ans = solve(queries, euler);
    for(int i = 0; i < q; ++i) cout << ans[i] << " \n"[i + 1 == q];
}
