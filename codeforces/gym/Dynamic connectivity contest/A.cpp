/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int N;

struct query{
    char t;
    int from, to;
};

struct edge{
    int from, to;
};

struct segment_tree{
    struct node{
        vector<int> edges;
        vector<int> lazy;
        bool neutro;
        node(bool _x):edges(vector<int>()), lazy(vector<int>()), neutro(_x){};
        node(vector<int> &e, vector<int> &lz): edges(e), lazy(lz){}

        node operator+(const node &b)const{
            node res(0);

            if(neutro) res.edges = b.edges;
            else if(b.neutro) res.edges = edges;
            else {
                vector<bool> ap(N);
                for(const int &e : b.edges) ap[e] = true;
                for(int e : edges)
                    if(ap[e]) res.edges.push_back(e);
            }

            return res;
        }
    };
    vector<node> nodes;
    int n;

    segment_tree(int _n){
        n = _n;
        nodes.resize(4 * n + 1, node(0));
    }

    void combine_lazy(vector<int> &lz, int pos){
        for(int &e : lz)
            nodes[pos].lazy.push_back(e);
    }

    void apply_lazy(int pos){
        for(int &e : nodes[pos].lazy)
            nodes[pos].edges.push_back(e);
        nodes[pos].lazy.clear();
    }

    void push_lazy(int pos, int left, int right){
        int tam = right - left + 1;
        if(1 < tam){
            combine_lazy(nodes[pos].lazy, pos * 2);
            combine_lazy(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lazy(pos);
    }

    void update(int e, int l, int r, int left, int right, int pos = 1){
        //push_lazy(pos, left, right);
        apply_lazy(pos);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            vector<int> v = {e};
            combine_lazy(v, pos);
            //push_lazy(pos, left, right);
            apply_lazy(pos);
            return;
        }

        int mid = (left + right) / 2;
        update(e, l, r, left, mid, pos * 2);
        update(e, l, r, mid + 1, right, pos * 2 + 1);
        //nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        //push_lazy(pos, left, right);
        apply_lazy(pos);
        if(r < left || right < l) return node(1);
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

struct dsu{
    struct action{
        int x_p, y_p;
        int rank_y, cnt_comp;
    };
    vector<int> RA, P;
    int cnt_comp;
    vector<action> actions;

    dsu(int n){
        RA.resize(n);
        P.resize(n);
        cnt_comp = n;
        for(int i = 0; i < n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    int root(int x){
        return (x == P[x] ? x : root(P[x]));
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);

        if(RA[x] > RA[y]) swap(x, y);
        actions.push_back({x, y, RA[y], cnt_comp});
        if(x == y) return;

        RA[y] += RA[x];
        P[x] = y;
        cnt_comp--;
    }

    void rollback(int times){
        while(times-- > 0 && actions.size()){
            action act = actions.back();
            actions.pop_back();

            RA[act.y_p] = act.rank_y;
            P[act.x_p] = act.x_p;
            cnt_comp = act.cnt_comp;
        }
    }
};

vector<edge> edges;

void solve(int l, int r, segment_tree &seg_tree, dsu &mset, int ans[]){
    if(l > r) return;
    //cout << "Paso: " << l + 1 << ' ' << r + 1 << '\n';
    vector<int> e_id = seg_tree.query(l, r, 0, seg_tree.n - 1).edges;
    //cout << "Join: ";
    for(int id : e_id){
        //cout << id + 1 << ' ';
        mset.join(edges[id].from, edges[id].to);
    } //cout << '\n';

    if(l == r){
        ans[l] = mset.cnt_comp;
        mset.rollback(e_id.size());
        return;
    }

    int mid = (l + r) / 2;
    solve(l, mid, seg_tree, mset, ans);
    solve(mid + 1, r, seg_tree, mset, ans);

    mset.rollback(e_id.size());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("connect.in");
    ofstream cout("connect.out");

    int n, k; cin >> n >> k;
    N = n;

    int cur_q = -1;
    map<pair<int, int>, int> idx_e;
    unordered_set<int> pending, pending_open;
    vector<int> e_l;

    vector<query> queries;
    for(int i = 0; i < k; ++i){
        char t;
        int from, to;
        cin >> t;
        if(t == '+' || t == '-') cin >> from >> to;
        else cur_q++;
        from--, to--;
        if(to < from) swap(from, to);

        queries.push_back({t, from, to});
    }

    segment_tree seg_tree(cur_q + 1);
    cur_q = -1;
    for(auto [t, from, to] : queries){
        if(t == '+'){
            if(!idx_e.count({from, to})){
                idx_e[{from, to}] = edges.size();
                edges.push_back({from, to});
                e_l.push_back(-1);
            }
            pending.insert(idx_e[{from, to}]);
            pending_open.insert(idx_e[{from, to}]);
        } else if(t == '-'){
            int pos = idx_e[{from, to}];
            if(e_l[pos] != -1){
                seg_tree.update(pos, e_l[pos], cur_q, 0, seg_tree.n - 1);
            }
            pending_open.erase(idx_e[{from, to}]);
        } else {
            cur_q++;
            for(int idx : pending)
                e_l[idx] = cur_q;
            pending.clear();
        }
    }

    for(int idx : pending_open){
        if(e_l[idx] == -1) continue;
        //cout << "Update " << idx + 1 << ' ' << e_l[idx] + 1 << ' ' << cur_q + 1 << '\n';
        seg_tree.update(idx, e_l[idx], cur_q, 0, seg_tree.n - 1);
    }

    dsu mset(n);
    int ans[cur_q + 2];
    solve(0, cur_q, seg_tree, mset, ans);

    for(int i = 0; i <= cur_q; ++i) cout << ans[i] << '\n';
}
