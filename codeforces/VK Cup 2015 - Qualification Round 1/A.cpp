/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<int> tree[], int p = -1){
    int res = 0;
    for(int v : tree[u]) res = max(res, dfs(v, tree, u));
    return res + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> idx;
    int cur_idx = 0;
    int n; cin >> n;
    vector<pair<int, int>> edges;
    for(int i = 0; i < n; ++i){
        string a, b;
        cin >> a >> b >> b;
        for(char &c : a) c += (c <= 'Z' ? 'a' - 'A' : 0);
        for(char &c : b) c += (c <= 'Z' ? 'a' - 'A' : 0);
        if(!idx.count(a)) idx[a] = cur_idx++;
        if(!idx.count(b)) idx[b] = cur_idx++;
        edges.push_back({idx[a], idx[b]});
    }

    vector<int> tree[cur_idx];
    for(auto [a, b] : edges) tree[b].push_back(a);

    cout << dfs(idx["polycarp"], tree) << '\n';
}
