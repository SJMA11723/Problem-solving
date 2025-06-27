#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> RA, P;

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
        RA[y] += RA[x];
        P[x] = y;
    }

    int size(int x){
        return RA[root(x)];
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

    int ans = 0;
    for(int i = 0; i < n; ++i) ans = max(ans, mset.size(i));
    cout << ans << '\n';
}
