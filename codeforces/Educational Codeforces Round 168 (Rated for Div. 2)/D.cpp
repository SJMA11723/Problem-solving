/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<int> tree[], int val[], int64_t add){
    if(add >= 1e15) return false;

    bool res = true;
    bool hoja = true;
    for(int v : tree[u]){
        if(val[v] - add >= 0) res = res && dfs(v, tree, val, add);
        else res = res && dfs(v, tree, val, 2 * add - val[v]);
        hoja = false;
    }

    if(hoja) res = val[u] - add >= 0;

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int val[n];
        for(int &x : val) cin >> x;
        vector<int> tree[n];
        for(int i = 1; i < n; ++i){
            int p; cin >> p; p--;
            tree[p].push_back(i);
        }

        int64_t l = 0, r = 1e15;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            if(dfs(0, tree, val, mid)) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 + val[0] << '\n';
    }
}
