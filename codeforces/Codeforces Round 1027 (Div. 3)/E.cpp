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

void dfs(int u, vi tree[], int arr[], ll ans[], ll sum1 = 0, ll sum2 = 0, int p = -1){
    sum1 = max(0ll, sum1  + arr[u]);
    sum2 = max(0ll, sum2 - arr[u]);
    ans[u] = sum1;
    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, arr, ans, sum2, sum1, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;
        vi tree[n];
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            tree[a].pb(b);
            tree[b].pb(a);
        }

        ll ans[n];
        dfs(0, tree, arr, ans);
        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}