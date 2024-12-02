/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int &L, int &R, vector<int> tree[], int p = -1, bool d = 0){
    for(int v : tree[u])
    if(v != p) dfs(v, L, R, tree, u, !d);
    if(d) R++;
    else L++;
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

    int L = 0, R = 0;
    dfs(0, L, R, tree);
    cout << 1ll * L * R - n + 1 << '\n';
}
