/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 998244353;

int bin_exp(int a, int64_t b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

struct edge{
    int from, to, w;

    bool operator<(const edge &b)const{
        return w < b.w;
    }
};

struct dsu{
    vector<int> RA, P;

    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(all(P), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    int64_t join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return 0;
        if(RA[x] >= RA[y]) swap(x, y);
        int64_t cnt_noedges = 1ll * RA[x] * RA[y] - 1;
        RA[y] += RA[x];
        P[x] = y;
        return cnt_noedges;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<edge> edges;
        for(int i = 1; i < n; ++i){
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            edges.push_back({a, b, c});
        }
        sort(all(edges));

        int ans = 1;
        dsu mset(n);
        for(edge &e : edges){
            int64_t cnt = mset.join(e.from, e.to);
            ans = 1ll * ans * bin_exp(s - e.w + 1, cnt) % MOD;
        }
        cout << ans << '\n';
    }
}
