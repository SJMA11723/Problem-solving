#/**
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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXVAL 100000

const ll MOD = 1e9 + 7;

vll phi_1_to_n(int n) {
    vll phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vll phi = phi_1_to_n(MAXVAL);
    for(int i = 1; i <= MAXVAL; ++i){
        phi[i] += phi[i - 1];
    }

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        cout << "Case " << tt << ": " << 1ll * n * (n + 1) / 2 - phi[n] << '\n';
    }
}
