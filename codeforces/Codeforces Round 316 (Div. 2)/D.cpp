/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 500001

using namespace std;

string letters;
vector<int> tree[MAXN];
int subtree_size[MAXN], depth[MAXN];
int cnt[MAXN][26], order[MAXN];
vector<pair<int, int>> query[MAXN];
bool big[MAXN], ans[MAXN];

void precalc(int node, int p = 0){
    subtree_size[node] = 1;
    depth[node] = depth[p] + 1;
    for(int v : tree[node]){
        if(v == p) continue;
        precalc(v, node);
        subtree_size[node] += subtree_size[v];
    }
}

/// sack
void add(int node, int x, int p = 0){
    cnt[depth[node]][letters[node - 1] - 'a'] += x;
    for(int v: tree[node])
        if(v != p && !big[v])
            add(v, x, node);
}

void dfs(int node, bool keep, int p = 0){
    int maxi = -1, big_child = -1;
    for(int v : tree[node]) /// Search for big_child
       if(v != p && subtree_size[v] > maxi)
          maxi = subtree_size[v], big_child = v;

    for(int v : tree[node])
        if(v != p && v != big_child)
            dfs(v, false, node);  /// run a dfs on small childs and clear them from cnt
    if(big_child != -1)
        dfs(big_child, true, node), big[big_child] = 1;  /// big_child marked as big and not cleared from cnt

    add(node, 1, p);
    for(auto [h, idx] : query[node]){
        int cnt_odd = 0;
        for(int i = 0; i < 26; ++i) cnt_odd += cnt[h][i] % 2;
        ans[idx] = cnt_odd <= 1;
    }


    if(big_child != -1)
        big[big_child] = 0;
    if(keep == 0)
        add(node, -1, p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 2; i <= n; ++i){
        int p; cin >> p;
        tree[p].push_back(i);
    }
    cin >> letters;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        query[a].push_back({b, i});
    }

    precalc(1);
    dfs(1, true);

    for(int i = 0; i < m; ++i) cout << (ans[i] ? "Yes\n" : "No\n");

}
