/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int w;

    bool operator<(const edge &b)const{
        return w < b.w;
    }
};

struct dsu{
    vector<int> RA, P;
    vector<vector<int>> sets;
    vector<int64_t> add;

    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
        add.resize(n);
        sets.resize(n);
        for(int i = 0; i < n; ++i) sets[i].push_back(i);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y, int w, int64_t ans[]){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[x] >= RA[y]) swap(x, y);
        add[y] += 1ll * RA[x] * w;
        add[x] += 1ll * RA[y] * w;
        for(int u : sets[x]){
            ans[u] += add[x] - add[y];
            sets[y].push_back(u);
        }
        RA[y] += RA[x];
        P[x] = y;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int64_t ans[n];
    for(int64_t &x : ans) cin >> x;

    vector<edge> edges(m);
    for(edge &e : edges){
        cin >> e.from >> e.to;
        e.from--, e.to--;
        e.w = max(ans[e.from], ans[e.to]);
    }

    sort(edges.begin(), edges.end());
    dsu mset(n);
    for(edge &e : edges) mset.join(e.from, e.to, e.w, ans);
    for(int i = 0; i < n; ++i) ans[i] += mset.add[mset.root(0)];
    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
