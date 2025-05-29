/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

void dfs(int u, vector<int> tree[], int st_size[], int p = -1){
    st_size[u] = 1;
    for(int v : tree[u])
    if(v != p){
        dfs(v, tree, st_size, u);
        st_size[u] += st_size[v];
    }
}

void dfs_reroot(int u, vector<int> tree[], int st_size[], int &ans, int p = -1){
    int acc = 0;
    for(int v : tree[u]){
        ans += 1ll * acc * st_size[v] % MOD;
        acc += st_size[v];
        if(ans >= MOD) ans -= MOD;
    }

    for(int v : tree[u]){
        if(v == p) continue;

        st_size[u] -= st_size[v];
        st_size[v] += st_size[u];
        dfs_reroot(v, tree, st_size, ans, u);
        st_size[v] -= st_size[u];
        st_size[u] += st_size[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    if(k % 2){
        cout << "1\n";
        return 0;
    }

    int ans = 1ll * n * (n - 1) % MOD, st_size[n];
    dfs(0, tree, st_size);
    dfs_reroot(0, tree, st_size, ans);

    ans += ans;
    if(ans >= MOD) ans -= MOD;
    ans = 1ll * ans * inv(1ll * n * (n - 1) % MOD) % MOD;
    cout << ans << '\n';
}
