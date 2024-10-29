/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

struct dsu{
    vector<int> RA, P;
    int64_t sum = 0;
    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[y] < RA[x]) swap(x, y);
        sum -= 1ll * RA[y] * (RA[y] - 1) / 2 + 1ll * RA[x] * (RA[x] - 1) / 2;
        RA[y] += RA[x];
        P[x] = y;
        sum += 1ll * RA[y] * (RA[y] - 1) / 2;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges[MAXVAL + 1];

    for(int i = 1; i < n; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges[c].push_back({a, b});
    }

    vector<int> queries[MAXVAL + 1];
    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        queries[x].push_back(i);
    }

    int64_t ans[m] = {};
    dsu mset(n);
    for(int i = 0; i <= MAXVAL; ++i){
        for(auto [u, v] : edges[i]){
            mset.join(u, v);
        }
        for(int id : queries[i]) ans[id] = mset.sum;
    }

    for(int i = 0; i < m; ++i) cout << ans[i] << " \n"[i + 1 == m];
}
