#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXN 1000000

const int MOD = 1e9 + 7;

struct dsu{
    vi P, RA;
    
    dsu(int n){
        P.resize(n);
        RA.resize(n, 1);
        iota(all(P), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[x] > RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
    }
};

vi cub[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr[i] = x;
        x--;
        cub[x].pb(i);
    }

    vi graph[n];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        if(arr[a] < arr[b]) swap(a, b);
        graph[a].pb(b);
    }

    dsu mset(n);
    int ans[n] = {};
    for(int e = 0; e <= MAXN; ++e){
        for(int u : cub[e])
        for(int v : graph[u]) mset.join(u, v);

        for(int u : cub[e]){
            ans[u] = mset.RA[mset.root(u)];
        }
    }

    for(int x : ans) cout << x << '\n';
}