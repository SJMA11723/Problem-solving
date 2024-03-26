/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'001

using namespace std;

const int64_t MOD = 1e9;

struct dsu{
    int RA[MAXN], P[MAXN];
    int64_t sum_pair;

    dsu(int n){
        for(int i = 0; i < n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
        sum_pair = 0;
    }

    int root(int x){
        if(x == P[x]) return x;
        return P[x] = root(P[x]);
    }

    void join(int x, int y){
        int Px = root(x);
        int Py = root(y);
        if(Px == Py) return;
        if(RA[Px] >= RA[Py]) swap(Px, Py);
        sum_pair += (int64_t)RA[Px] * RA[Py] % MOD;
        sum_pair %= MOD;
        RA[Py] += RA[Px];
        P[Px] = Py;
    }
};

struct edge{
    int from, to;
    int64_t w;
    bool operator>(const edge &b)const{
        return w > b.w;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges;
    while(m--){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end(), greater<edge>());
    dsu mset(n);
    int64_t ans = 0;
    for(edge &e : edges){
        mset.join(e.from, e.to);
        ans += e.w * mset.sum_pair % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
