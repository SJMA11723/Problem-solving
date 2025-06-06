/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

const int MOD = 1e9 + 7;

struct dsu{
    vector<int> P, RA;
    int cnt_comp;

    dsu(int n){
        cnt_comp = n;
        P.resize(n);
        RA.resize(n, 1);
        iota(all(P), 0);
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

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x, x--;

        dsu mset(n);
        for(int i = 0; i < n; ++i){
            int x; cin >> x; x--;
            mset.join(x, arr[i]);
        }

        cout << bin_exp(2, mset.cnt_comp) << '\n';
    }
}
