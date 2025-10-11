/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

void dfs(int u, vi tree[], int dp[][2], int p = -1){
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, dp, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vi tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    int dp[n][2];
    memset(dp, -1, sizeof(dp));
    dfs(0, tree, dp);

    int max_match = n - max(dp[0][0], dp[0][1]);
    cout << 2 * (n - max_match) - max_match << '\n';
}