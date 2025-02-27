/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> tree[n + 1];
        for(int i = 2; i <= n; ++i){
            int p; cin >> p;
            tree[p].push_back(i);
        }

        int cnt_len[n + 1] = {};
        int cnt[n + 1] = {};
        queue<tuple<int, int, int>> q;
        q.push({1, 0, 1});
        cnt_len[1] = 1;
        cnt[1] = 1;
        while(q.size()){
            int u, p, d;
            tie(u, p, d) = q.front();
            q.pop();

            cnt[u] = (cnt_len[d - 1] - (p == 1 ? 0 : cnt[p]) + MOD) % MOD;

            cnt_len[d] += cnt[u];
            if(cnt_len[d] >= MOD) cnt_len[d] -= MOD;

            for(int v : tree[u]) q.push({v, u, d + 1});
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            ans += cnt_len[i];
            if(ans >= MOD) ans -= MOD;
        }
        cout << ans << '\n';
    }
}
