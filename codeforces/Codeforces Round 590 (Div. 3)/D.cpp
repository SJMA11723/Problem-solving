/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define lsb(n) ((n) & -(n))

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
    string s; cin >> s;
    int n = s.size();
    s = "#" + s;
    vector<fenwick_tree> cnt(26, fenwick_tree(n));

    for(int i = 1; i <= n; ++i) cnt[s[i] - 'a'].add(i, 1);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i;
            char c; cin >> c;
            cnt[s[i] - 'a'].add(i, -1);
            cnt[c - 'a'].add(i, 1);
            s[i] = c;
        } else {
            int l, r; cin >> l >> r;
            int ans = 0;
            for(int c = 0; c < 26; ++c) ans += 0 < cnt[c].sum(r) - cnt[c].sum(l - 1);
            cout << ans << '\n';
        }
    }
}
