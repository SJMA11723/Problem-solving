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

#define LOGN 18

bool deb = 0;

#define DEBUG if(deb)

const ll MOD = 1e9 + 7;

vi depth, subtree_size, T;
vector<vi> tree;
vector<bool> big;

void precalc(int u, int p = 0){
    depth[u] = depth[p] + 1;
    subtree_size[u] = 1;

    for(int v : tree[u]){
        if(v == p) continue;
        precalc(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

set<pair<ll, int>> mset;
map<int, ll> sum;

void add(int u, int x, int p = 0){
    // to-do
    if(u > 1){
        int d = depth[u];
        mset.erase({sum[d], -d});
        sum[d] += T[u] * x;
        DEBUG cout << " Actualiza " << u << ' ' << d << ' ' << sum[d] << '\n';
        mset.insert({sum[d], -d});
    }

    for(int v : tree[u])
        if(p != v && !big[v]) add(v, x, u);
}

void dfs(int u, bool keep, pair<ll, int> &ans, int p = 0){
    int maxi = -1, big_child = -1;
    for(int v : tree[u]){
        if(v != p && subtree_size[v] > maxi){
            maxi = subtree_size[v];
            big_child = v;
        }
    }

    for(int v : tree[u]){
        if(v != p && v != big_child){
            dfs(v, false, ans, u);
        }
    }

    if(big_child != -1){
        dfs(big_child, true, ans, u);
        big[big_child] = 1;
    }

    DEBUG cout << "Add " << u << '\n';
    add(u, 1, p);

    /// TO-DO
    if(u > 1){
        pair<ll, int> cur_max = *mset.rbegin();
        cur_max.se *= -1;

        DEBUG cout << "ANS = " << ans.fi << ' ' << ans.se << '\n';

        if(cur_max.fi > ans.fi){
            ans.fi = cur_max.fi;
            ans.se = cur_max.se - depth[u] + 1;
        } else if(cur_max.fi == ans.fi && ans.se > cur_max.se - depth[u] + 1){
            ans.se = cur_max.se - depth[u] + 1;
        }

        DEBUG cout << "ANS = " << ans.fi << ' ' << ans.se << '\n';
    }

    if(big_child != -1) big[big_child] = 0;
    if(!keep) add(u, -1, p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    T.resize(n + 1);
    depth.resize(n + 1);
    subtree_size.resize(n + 1);
    tree.resize(n + 1);
    big.resize(n + 1);

    for(int i = 2; i <= n; ++i) cin >> T[i];

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    precalc(1);

    pair<ll, int> ans = {0, 1};
    dfs(1, 1, ans);

    cout << ans.fi << ' ' << ans.se << '\n';
}