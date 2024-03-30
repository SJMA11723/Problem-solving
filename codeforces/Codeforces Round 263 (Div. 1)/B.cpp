/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100000
#define BLACK 1
#define WHITE 0

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t bin_exp(int64_t a, int64_t b){
    if(!b) return 1;

    int64_t tmp = bin_exp(a, b / 2);

    if(b % 2) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

vector<int> tree[MAXN];
bool color[MAXN];
int64_t dp[MAXN][2];

void dfs(int node, int p = -1){
    dp[node][color[node]] = 1;
    dp[node][!color[node]] = 0;

    for(int v : tree[node]){
        if(v == p) continue;
        dfs(v, node);

        dp[node][color[node]] = dp[node][color[node]] * (dp[v][WHITE] + dp[v][BLACK]) % MOD;
    }


    for(int v : tree[node]){
        if(v == p) continue;

        if(!color[node]){
            dp[node][BLACK] += dp[v][BLACK] * dp[node][color[node]] % MOD * bin_exp(dp[v][WHITE] + dp[v][BLACK], MOD - 2) % MOD;
            dp[node][BLACK] %= MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; ++i){
        int p; cin >> p;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }

    for(int i = 0; i < n; ++i) cin >> color[i];

    dfs(0);

    cout << dp[0][1] << '\n';
}
