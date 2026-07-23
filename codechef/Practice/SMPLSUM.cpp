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
#define MAXN 10'000'000

const int MOD = 1e9 + 7;

int phi[MAXN + 1];
vi divs[MAXN + 1];
bool vis[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    iota(phi, phi + MAXN + 1, 0);
    for(int i = 2; i <= MAXN; ++i) if(phi[i] == i)
    for(int j = i; j <= MAXN; j += i)
        phi[j] -= phi[j] / i;

    int t; cin >> t;
    int queries[t];
    for(int &n : queries){
        cin >> n;
        vis[n] = 1;
    }

    for(int i = 2; i <= MAXN; ++i)
    for(int j = 2 * i; j <= MAXN; j += i)
        if(vis[j]) divs[j].pb(i);

    for(int n : queries){
        ll ans = 1 + ll(n != 1) * phi[n] * n;
        for(int d : divs[n]) ans += 1ll * phi[d] * d;
        cout << ans << '\n';
    }
}