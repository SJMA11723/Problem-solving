/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], bool init[], bool goal[], vector<int> &ans, bool d_e = false, bool d_o = false, bool d = false, int p = -1){
    if(d && d_o) init[u] ^= 1;
    else if(!d && d_e) init[u] ^= 1;

    if(init[u] != goal[u]){
        ans.push_back(u + 1);
        if(d) d_o ^= 1;
        else d_e ^= 1;
    }

    d ^= 1;
    for(int v : tree[u])
        if(v != p) dfs(v, tree, init, goal, ans, d_e, d_o, d, u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bool init[n];
    for(bool &x : init) cin >> x;

    bool goal[n];
    for(bool &x : goal) cin >> x;

    vector<int> ans;
    dfs(0, tree, init, goal, ans);
    cout << ans.size() << '\n';
    for(int u : ans) cout << u << '\n';
}
