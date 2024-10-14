#include <bits/stdc++.h>
#define lsb(S) ((S) & -(S))

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t; cin >> n >> t;
    fenwick_tree BIT(n);
    while(t--){
        char t; cin >> t;
        if(t == 'R'){
            int idx; cin >> idx;
            BIT.add(idx, 1);
        } else {
            int l, r; cin >> l >> r;
            cout << r - l + 1 - BIT.sum(r) + BIT.sum(l - 1) << '\n';
        }
    }
}
