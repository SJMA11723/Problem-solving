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

ll bellman_ford(int n, vector<edge> &edges){
    vll d(n, 0);
    for(int i = 1; i < n; ++i)
    for(edge &e : edges){
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
        }
    }
    for(edge &e : edges){
        if(d[e.to] > d[e.from] + e.w){
            return -1;
        }
    }
    return d[n - 1] - d[0];
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int l, r, s; cin >> l >> r >> s;
        edges.pb({l - 1, r, s});
        edges.pb({r, l - 1, -s});
    }
    for(int i = 1; i <= n; ++i) edges.pb({i, i - 1, -1});
    cout << bellman_ford(n + 1, edges) << '\n';
}