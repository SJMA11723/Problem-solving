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

// rooted at 0
// dps[i]: subtree ans if s[i] = 'S'
// dpp[i]: subtree ans if s[i] = 'P'
void dfs(int u, vi tree[], const string &s, ll dps[], ll dpp[], int p = -1){
    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, s, dps, dpp, u);
        dps[u] += min(dps[v], dpp[v] + 1);
        dpp[u] += min(dps[v] + 1, dpp[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi tree[n];
        for(int i = 1; i < n; ++i){
            int a; cin >> a; a--;
            tree[i].pb(a);
            tree[a].pb(i);
        }

        string s; cin >> s;
        ll dps[n], dpp[n];
        for(int i = 0; i < n; ++i){
            if(s[i] == 'S') dps[i] = 0, dpp[i] = 1e9;
            else if(s[i] == 'P') dps[i] = 1e9, dpp[i] = 0;
            else dps[i] = dpp[i] = 0;
        }
        dfs(0, tree, s, dps, dpp);
        cout << min(dps[0], dpp[0]) << '\n';
    }
}