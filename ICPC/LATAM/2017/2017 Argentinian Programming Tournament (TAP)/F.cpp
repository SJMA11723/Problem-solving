#include <bits/stdc++.h>
#define lsb(n) ((n) & -(n))

#define MAXN 100000

using namespace std;

struct fenwick_tree{
    int n;
    vector<int> BIT;
    fenwick_tree(int _n){
        n = _n;
        BIT.resize(n + 1);
    }

    void add(int pos, int x){
        while(pos <= n){
            BIT[pos] += x;
            pos += lsb(pos);
        }
    }

    int sum(int pos){
        int res = 0;
        while(pos){
            res += BIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }
};

struct event{
    int l, r, v;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    fenwick_tree bit(MAXN + 2);
    vector<event> arr;
    while(q--){
        int c; cin >> c;
        if(c == 1){
            int l, r, v;
            cin >> l >> r >> v;
            bit.add(l, v);
            bit.add(r, -v);
            arr.push_back({l, r, v});
        } else if(c == 2){
            int k; cin >> k; k--;
            event e = arr[k];
            bit.add(e.l, -e.v);
            bit.add(e.r, e.v);
        } else {
            int l, r; cin >> l >> r;
            cout << bit.sum(r) - bit.sum(l - 1) << '\n';
        }
    }
}
