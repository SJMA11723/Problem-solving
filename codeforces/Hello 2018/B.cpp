/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<int> tree[]){
    bool res = true;
    int cnt = 0;
    for(int v : tree[u]){
        res &= dfs(v, tree);
        if(tree[v].empty()) cnt++;
    }
    res &= tree[u].empty() || cnt >= 3;

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int p; cin >> p; p--;
        tree[p].push_back(i);
    }
    cout << (dfs(0, tree) ? "Yes\n" : "No\n");
}
