/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> RA, P;
    int cnt_comp;
    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
        cnt_comp = n;
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
        cnt_comp--;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    dsu mset(n);
    for(int i = 0; i < n; ++i){
        int p; cin >> p; p--;
        mset.join(i, p);
    }
    cout << mset.cnt_comp << '\n';
}
