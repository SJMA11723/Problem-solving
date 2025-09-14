#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>> &tree, vector<int> &euler){
    euler.push_back(u);
    for(int v : tree[u]) dfs(v, tree, euler);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> tree(2);
    vector<bool> died(2);

    int q; cin >> q;
    pair<int, int> queries[q];
    for(auto &[t, u] : queries){
        cin >> t >> u;
        if(t == 1){
            tree[u].push_back(tree.size());
            tree.push_back({});
            died.push_back(0);
        }
    }

    vector<int> euler;
    dfs(1, tree, euler);

    int cur_monarch = 0;
    for(auto &[t, u] : queries){
        if(t == 2){
            died[u] = true;
            while(died[euler[cur_monarch]]) cur_monarch++;
            cout << euler[cur_monarch] << '\n';
        }
    }
}
