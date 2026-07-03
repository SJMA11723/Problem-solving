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

void dfs(int u, vi tree[], long double proba[], int p = -1, int d = 0, long double pr = 1){
    if((u == 0 && sz(tree[u]) == 0) || (u > 0 && sz(tree[u]) == 1)){
        proba[d] += pr;
        return;
    }
    pr /= sz(tree[u]) - 1 * (u > 0);
    for(int v : tree[u]) if(v != p) dfs(v, tree, proba, u, d + 1, pr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vi tree[n];
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    long double proba[n] = {};
    dfs(0, tree, proba);
    long double ans = 0;
    for(int i = 1; i < n; ++i) ans += i * proba[i];
    cout << fixed << setprecision(7) << ans << '\n';
}