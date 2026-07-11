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

bool bellman_ford(int s, int n, vector<edge> &edges, bool cycles = 0){
    vll d(n, cycles ? 0 : LLONG_MAX);
    d[s] = 0;
    for(int i = 1; i < n; ++i)
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
        }
    }
    for(edge &e : edges){
        if(d[e.from] == LLONG_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while(cin >> n){
        if(n == 0) break;
        cin >> m;
        vector<edge> edges;
        for(int i = 0; i < m; ++i){
            int si, ni; cin >> si >> ni;
            string oi; cin >> oi;
            int ki; cin >> ki;
            if(oi == "lt") edges.pb({si - 1, si + ni, ki - 1});
            else edges.pb({si + ni, si - 1, -(ki + 1)});
        }
        if(bellman_ford(0, n + 1, edges, 1)) cout << "lamentable kingdom\n";
        else cout << "successful conspiracy\n";
    }
}