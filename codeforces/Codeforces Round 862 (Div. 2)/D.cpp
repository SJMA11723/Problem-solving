/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int depth_diam;
int D[100001];

void dfs(int node, vector<int> tree[], int &e, bool save = false, int p = -1, int d = 0){
    if(d > depth_diam){
        depth_diam = d;
        e = node;
    }

    if(save)
        D[node] = max(D[node], d);

    for(int v : tree[node])
        if(v != p) dfs(v, tree, e, save, node, d + 1);
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

    int end1, end2;
    dfs(0, tree, end1);
    depth_diam = 0;
    dfs(end1, tree, end2, true);
    dfs(end2, tree, end1, true);

    //cout << "-------------\n";

    int cub[n] = {};
    for(int i = 0; i < n; ++i){
        cub[ D[i] - 1 ]++;
        //cout << i + 1 << ' ' << D[i] << '\n';
    }
    cub[*max_element(D, D + n) - 1]--;

    int ans[n], cnt = n;
    for(int i = n - 1; 0 <= i; --i){
        cnt -= cub[i];
        ans[i] = cnt;
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n];
}
