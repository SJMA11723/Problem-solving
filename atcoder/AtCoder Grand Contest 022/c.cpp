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
const ll INF = 1e18;

vvll floyd_warshall(int n, ll edges){
    vvll d(n, vll(n, INF));
    for(int i = 0; i < n; ++i)
    for(int j = 1; j < n; ++j)
        if(edges & (1ll << j)) d[i][i % j] = min(d[i][i % j], 1ll << j);
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
    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    if(equal(a, a + n, b, b + n)){
        cout << "0\n";
        return 0;
    }

    ll ans = (1ll << 51) - 2;
    for(int k = 50; 0 < k; --k){
        vvll d = floyd_warshall(51, ans ^ (1ll << k));
        bool ok = 1;
        for(int i = 0; i < n; ++i) if(d[a[i]][b[i]] == INF){
            ok = 0;
            break;
        }
        if(ok) ans ^= 1ll << k;
    }
    cout << (ans == ((1ll << 51) - 2) ? -1 : ans) << '\n';
}
