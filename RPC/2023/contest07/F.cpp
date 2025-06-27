/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct FenwickTree{
    ll n, *BIT;

    FenwickTree(int n_size){
        n = n_size + 1;
        BIT = new ll[n];
        memset(BIT, 0, sizeof(ll) * n);
    }

    void add(int pos, ll x){
        while(pos <= n){
            BIT[pos] += x;
            pos += pos & -pos;
        }
    }

    ll sum(int pos){
        ll ret = 0;
        while(pos){
            ret += BIT[pos];
            pos -= pos & -pos;
        }
        return ret;
    }

    ~FenwickTree(){
        delete[] BIT;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    FenwickTree BIT(n);
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        BIT.add(i, x);
    }

    int t; cin >> t;
    while(t--){
        char c; cin >> c;
        if(c == 'U'){
            int pos, x;
            cin >> pos >> x;
            BIT.add(pos, x);
        } else {
            int a, b; cin >> a >> b;
            cout << BIT.sum(b) - BIT.sum(a - 1) << '\n';
        }
    }
}
