/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
};

struct dsu{
    struct action{
        int x_p, y_p;
        int rank_y;
    };
    vector<int> RA, P;
    vector<action> actions;

    dsu(int n){
        RA.resize(n);
        P.resize(n);
        for(int i = 0; i < n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    int root(int x){
        return (x == P[x] ? x : root(P[x]));
    }

    bool are_connected(int x, int y){
        return root(x) == root(y);
    }

    void join(int x, int y, bool recording){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(RA[x] >= RA[y]) swap(x, y);

        if(recording) actions.push_back({x, y, RA[y]});
        RA[y] += RA[x];
        P[x] = y;
    }

    void rollback(int times){
        while(times-- > 0 && actions.size()){
            action act = actions.back();
            actions.pop_back();

            RA[act.y_p] = act.rank_y;
            P[act.x_p] = act.x_p;
        }
    }
};

vector<edge> edges;

int64_t compute(int l, int r, vector<int> cub[], dsu &mset){
    if(l == r){
        int64_t res = 0;
        for(int idx : cub[l]){
            auto [from, to] = edges[idx];
            res += (int64_t)mset.RA[mset.root(from)] * mset.RA[mset.root(to)];
        }
        return res;
    }

    int64_t res = 0;
    int mid = (l + r) / 2;
    int cnt = 0;
    for(int i = mid + 1; i <= r; ++i){
        cnt += cub[i].size();
        for(int idx : cub[i]){
            auto [from, to] = edges[idx];
            mset.join(from, to, true);
        }
    }
    res += compute(l, mid, cub, mset);
    mset.rollback(cnt);

    cnt = 0;
    for(int i = l; i <= mid; ++i){
        cnt += cub[i].size();
        for(int idx : cub[i]){
            auto [from, to] = edges[idx];
            mset.join(from, to, true);
        }
    }
    res += compute(mid + 1, r, cub, mset);
    mset.rollback(cnt);

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> cub[n];
    for(int i = 1; i < n; ++i){
        int a, b, x; cin >> a >> b >> x;
        a--, b--, x--;
        cub[x].push_back(edges.size());
        edges.push_back({a, b});
    }

    dsu mset(n);
    cout << compute(0, n - 1, cub, mset) << '\n';
}
