/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define set_bit(n, i) n |= (1ll << (i))
#define clear_bit(n, i) n &= ~(1ll << (i))
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

void dfs(int u, const int s, vector<pair<int, int>> tree[], vector<vector<int64_t>> &path_set, int64_t mset = 0, int p = -1){
    for(auto [v, e_idx] : tree[u]){
        if(v == p) continue;
        set_bit(mset, e_idx);
        path_set[s][v] = mset;
        dfs(v, s, tree, path_set, mset, u);
        clear_bit(mset, e_idx);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back({b, i - 1});
        tree[b].push_back({a, i - 1});
    }

    vector<vector<int64_t>> path_set(n, vector<int64_t>(n, 0));
    for(int i = 0; i < n; ++i) dfs(i, i, tree, path_set);

    int m; cin >> m;
    pair<int, int> restrictions[m];
    for(pair<int, int> &p : restrictions){
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
    }

    int64_t ans = 0;
    int lim = 1 << m;
    for(int mask = 1; mask < lim; ++mask){
        int64_t mset = 0;
        for(int i = 0; i < m; ++i)
        if(is_on(mask, i)) mset |= path_set[restrictions[i].first][restrictions[i].second];

        int k = __builtin_popcountll(mset);
        ans += ((1ll << (n - 1)) - (1ll << (n - 1 - k))) * (__builtin_parity(mask) ? 1 : -1);
    }
    cout << ans << '\n';
}
