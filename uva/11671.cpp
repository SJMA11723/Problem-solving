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
    int w;
};

bool bellman_ford(int n, vector<edge> &edges, vi &d){
    fill(all(d), 0);
    for(int i = 1; i < n; ++i)
    for(edge &e : edges){
        if(d[e.from] == INT_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
        }
    }
    for(edge &e : edges){
        if(d[e.from] == INT_MAX) continue;
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
    int n, t = 1;
    while(cin >> n){
        if(n == -1) break;
        // F_i: suma total en fila i
        // C_i: suma total en columna i
        // X_i := F_i para i < n
        // X_i := -C_{i - n} para n <= i
        // M_{ij} = '+' <=> X_i - X_{j + n} > 0 <=> X_{j + n} - X_i <= -1
        // M_{ij} = '-' <=> X_i - X_{j + n} < 0 <=> X_i - X_{j + n} <= -1
        // M_{ij} = '0' <=> X_i - X_{j + n} = 0 <=> X_i - X_{j + n} <= 0 && X_{j + n} - X_i <= 0
        vector<edge> edges;
        int N = 2 * n;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            char c; cin >> c;
            if(c == '+') edges.pb({i, j + n, -1});
            else if(c == '-') edges.pb({j + n, i, -1});
            else {
                edges.pb({i, j + n, 0});
                edges.pb({j + n, i, 0});
            }
        }

        vi X(N);
        cout << "Case " << t++ << ": ";
        if(bellman_ford(N, edges, X)){
            nth_element(X.begin(), X.begin() + n, X.end());
            int ans = 0;
            for(int x : X) ans += abs(x - X[n]);
            cout << ans << '\n';
        } else cout << "-1\n";
    }
}
