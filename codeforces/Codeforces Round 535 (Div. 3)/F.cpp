/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;

    bool operator<(const edge &b){
        return w < b.w;
    }
};

struct dsu{
    vector<int> RA, P;
    dsu(int n){
        RA.resize(n + 1, 1);
        P.resize(n + 1);
        iota(P.begin(), P.end(), 0);
    }

    void reset(){
        fill(RA.begin(), RA.end(), 1);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    bool same_set(int x, int y){
        return root(x) == root(y);
    }

    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};

int kruskal(int n, vector<edge> &edges){
    if(edges.empty()) return 0;

    sort(edges.begin(), edges.end());
    edges.push_back({0, n, INT_MAX});
    dsu mset(n);

    vector<edge> same_w;
    int res = 0, prev_w = 0;
    for(edge &e : edges){
        if(e.w == prev_w){
            if(!mset.same_set(e.from, e.to)) same_w.push_back(e);
            continue;
        }

        for(edge &e2 : same_w)
            if(!mset.join(e2.from, e2.to)) res++;

        same_w.clear();
        if(!mset.same_set(e.from, e.to)) same_w.push_back(e);
        prev_w = e.w;
    }

    edges.pop_back();
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    for(edge &e : edges) cin >> e.from >> e.to >> e.w, e.from--, e.to--;
    cout << kruskal(n, edges) << '\n';
}
