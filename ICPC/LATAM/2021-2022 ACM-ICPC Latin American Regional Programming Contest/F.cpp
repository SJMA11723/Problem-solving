#include <bits\stdc++.h>

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

    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    dsu mset(n);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        if(u != n - 1 && v != n - 1) mset.join(u, v);
    }

    for(int i = 0; i < n; ++i) cout << (mset.root(i) == mset.root(n - 2) ? 'B' : 'A');
    cout << '\n';
}
