/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<int> tree[], int p = -1){
    int res = 0;
    for(int v : tree[u])
        if(v != p) res = max(res, dfs(v, tree, u));
    return res + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    int p[n];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        if(p[i] == -1) continue;
        else {
            p[i]--;
            tree[p[i]].push_back(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(p[i] == -1) ans = max(ans, dfs(i, tree));

    cout << ans << '\n';
}
