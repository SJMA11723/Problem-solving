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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

void dfs(int u, vi graph[], char vis[], vvi &ans, int p = -1){
    vis[u] = 1;
    vi pending;
    for(int v : graph[u]){
        if(vis[v]){
            if(vis[v] == 2) pending.pb(v);
            continue;
        }
        dfs(v, graph, vis, ans, u);
        if(!sz(ans) || ans.back()[0] != u || ans.back()[1] != v)
            pending.pb(v);
    }
    while(sz(pending) > 1){
        int a = pending.back(); pending.pop_back();
        int b = pending.back(); pending.pop_back();
        ans.pb({a, u, b});
    }
    if(sz(pending) && p != -1) ans.pb({p, u, pending[0]});
    vis[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vi graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    char vis[n + 1] = {};
    vvi ans;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        dfs(i, graph, vis, ans);
    }
    cout << sz(ans) << '\n';
    for(vi &e : ans) cout << e[0] << ' ' << e[1] << ' ' << e[2] << '\n';
}
