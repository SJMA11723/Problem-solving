#include<bits/stdc++.h>
#define MAXN 1'000'000

using namespace std;

vector<int> tree[MAXN + 1];
int prize[MAXN + 1][2];

int64_t subtree_prize[MAXN + 1];
int64_t ind_prize[MAXN + 1];

int64_t dfs(int node){
    int64_t res = prize[node][1];

    for(int v : tree[node]){
        res += dfs(v);
        subtree_prize[node] += subtree_prize[v];
    }
    subtree_prize[node] += res + prize[node][0];
    ind_prize[node] = res + prize[node][0];

    //cout << node << ' ' << ind_prize[node] << ' ' << subtree_prize[node] << '\n';

    return res;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    int root;

    for(int i = 1; i <= N; ++i){
        int id; cin >> id;
        if(id) tree[id].push_back(i);
        else root = i;
    }

    while(M--){
        int m, e, v;
        cin >> m >> e >> v;
        prize[e][m == 2] += v;
    }

    dfs(root);

    while(Q--){
        int t, e;
        cin >> t >> e;
        if(t == 1) cout << ind_prize[e] << '\n';
        else cout << subtree_prize[e] << '\n';
    }

    return 0;
}
