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

struct edge{
    int from, to;
    ll w;
};

vvi floyd_warshall(int n, vector<edge> &edges){
    const int INF = 1e9;
    vvi d(n, vi(n, INF));
    for(edge &e : edges) d[e.from][e.to] = d[e.to][e.from] = e.w;
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, m, f; cin >> n >> m >> f;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int x, y, z; cin >> x >> y >> z;
            x--, y--;
            edges.pb({x, y, z});
        }
        vvi d = floyd_warshall(n, edges);

        int arr[f + 2];
        arr[0] = 0;
        for(int i = 1; i <= f; ++i){
            cin >> arr[i]; arr[i]--;
        }
        arr[f + 1] = n - 1;

        sort(arr + 1, arr + f + 1);
        int ans = INT_MAX;
        do{
            int cur_cost = 0;
            for(int i = 0; i <= f; ++i) cur_cost += d[arr[i]][arr[i + 1]];
            ans = min(ans, cur_cost);
        }while(next_permutation(arr + 1, arr + f + 1));
        cout << "Case " << tt << ": " << ans << '\n';
    }
}