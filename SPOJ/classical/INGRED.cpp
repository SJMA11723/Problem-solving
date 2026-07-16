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

#define is_on(S, i) ((S) & (1 << (i)))

const int MOD = 1e9 + 7;

struct edge{
    int from, to, w;
};

const int INF = 1e9;

vvi floyd_warshall(int n, vector<edge> &edges){
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
    int n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges.pb({a, b, c});
    }
    int s; cin >> s;
    int stores[s];
    for(int &x : stores) cin >> x;
    int kid1, kid2; cin >> kid1 >> kid2;

    vvi d = floyd_warshall(n, edges);
    int lim = 1 << s;
    int dp1[lim][s], dp2[lim][s];
    int mindp1[lim], mindp2[lim];
    mindp1[0] = mindp2[0] = 0;
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for(int mask = 1; mask < lim; ++mask){
        mindp1[mask] = mindp2[mask] = INF;
        for(int i = 0; i < s; ++i){
            dp1[mask][i] = dp2[mask][i] = INF;
            
            if(!is_on(mask, i)) continue;
            
            if(__builtin_popcount(mask) == 1){
                dp1[mask][i] = d[kid1][stores[i]];
                dp2[mask][i] = d[kid2][stores[i]];
                mindp1[mask] = d[kid1][stores[i]];
                mindp2[mask] = d[kid2][stores[i]];
                continue;
            }

            int prv_mask = mask ^ (1 << i);
            int minkid1 = INF;
            int minkid2 = INF;
            for(int j = 0; j < s; ++j) if(is_on(prv_mask, j)){
                minkid1 = min(minkid1, dp1[prv_mask][j] + d[stores[j]][stores[i]]);
                minkid2 = min(minkid2, dp2[prv_mask][j] + d[stores[j]][stores[i]]);
            }
            dp1[mask][i] = minkid1;
            dp2[mask][i] = minkid2;
            mindp1[mask] = min(mindp1[mask], minkid1);
            mindp2[mask] = min(mindp2[mask], minkid2);
        }
    }

    int ans = INF;
    int supermask = lim - 1;
    for(int mask = 0; mask < lim; ++mask)
        ans = min(ans, mindp1[mask] + mindp2[supermask ^ mask]);
    cout << ans << '\n';
}