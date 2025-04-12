#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> P, RA, cnt_edges;
    dsu(int n){
        P.resize(n);
        RA.resize(n, 1);
        cnt_edges.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y){
            cnt_edges[x]++;
            return;
        }

        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        cnt_edges[y] += cnt_edges[x] + 1;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    dsu mset(n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        mset.join(a, b);
    }

    bool vis[n] = {};
    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        if(vis[mset.root(i)]) continue;
        int p = mset.root(i);
        ans += 1ll * mset.RA[p] * (mset.RA[p] - 1) / 2 - mset.cnt_edges[p];
        vis[p] = true;
    }
    cout << ans << '\n';
}
