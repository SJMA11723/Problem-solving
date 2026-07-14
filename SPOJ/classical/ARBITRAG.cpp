/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vld> vvld;
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
    ld w;
};

bool floyd_warshall(int n, vector<edge> &edges){
    const ld INF = LLONG_MIN + 1;
    vvld d(n, vld(n, INF));
    for(edge &e : edges) d[e.from][e.to] = e.w;
    for(int i = 0; i < n; ++i) d[i][i] = max(d[i][i], (ld)1);
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            if(d[i][k] == INF) continue;
            for(int j = 0; j < n; ++j){
                if(d[k][j] == INF) continue;
                if(-d[i][j] > -(d[i][k] * d[k][j])){
                    d[i][j] = d[i][k] * d[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) if(d[i][i] > 1) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t = 1;
    while(cin >> n){
        if(n == 0) break;
        map<string, int> idx;
        for(int i = 0; i < n; ++i){
            string s; cin >> s;
            idx[s] = i;
        }
        int m; cin >> m;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            string c1, c2;
            ld w;
            cin >> c1 >> w >> c2;
            edges.pb({idx[c1], idx[c2], w});
        }
        cout << "Case " << t++ << ": " << (floyd_warshall(n, edges) ? "Yes\n" : "No\n");
    }
}
