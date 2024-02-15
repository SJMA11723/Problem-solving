/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100000

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

    int64_t w = 1;
    for(int v : tree[node]){
        if(v == p) continue;
        dfs(v, node);

        /*if(color[node]){
            if(dp[v][1]) dp[node][1] = dp[node][1] * (dp[v][0] + 1) % MOD;
        } else {
            if(dp[v][1]) dp[node][0] = dp[node][0] * (dp[v][0] + 1) % MOD;
        }*/
        if(dp[v][1]){
            dp[node][color[node]] = dp[node][color[node]] * (dp[v][0] + 1) % MOD;
        }
    }


    for(int v : tree[node]){
        if(v == p) continue;

        if(!color[node]){
            dp[node][1] += dp[v][1] * dp[node][0] % MOD * bin_exp(dp[v][0] + 1, MOD - 2) % MOD;
            dp[node][1] %= MOD;
            //cout << node << ": " << dp[v][1] << '\n';
        }
    }

    cout << node << ' ' << dp[node][0] << ' ' << dp[node][1] << '\n';
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
