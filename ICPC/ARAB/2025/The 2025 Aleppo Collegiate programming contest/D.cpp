/**
* Author: Mäthgic Crüe
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

void dfs(int u, vector<vector<char>> &adj, vpii &ans, bool vis[]){
    vis[u] = 1;
    for(int v = 0; v < sz(adj); ++v){
        if(!adj[u][v] || vis[v]) continue;
        dfs(v, adj, ans, vis);
        ans.pb({u + 1, v + 1});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<char>> adj(n, vector<char>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> adj[i][j];
                if(adj[i][j] == '?') adj[i][j] = 2;
                else adj[i][j] -= '0';
            }
        }

        vpii ans;
        bool vis[n] = {};
        dfs(0, adj, ans, vis);
        if(sz(ans) == n - 1){
            cout << "Yes\n";
            for(auto [a, b] : ans) cout << a << ' ' << b << '\n';
        } else cout << "No\n";
    }
}