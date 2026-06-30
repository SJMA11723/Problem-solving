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

ll mult(ll l, ll r, ll d){
    return r / d - (l - 1) / d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        int primes[] = {2, 3, 5, 7};
        ll ans = r - l + 1;
        ans -= mult(l, r, 2) + mult(l, r, 3) + mult(l, r, 5) + mult(l, r, 7);
        ans += mult(l, r, 6) + mult(l, r, 10) + mult(l, r, 14) + mult(l, r, 15) + mult(l, r, 21) + mult(l, r, 35);
        ans -= mult(l, r, 30) + mult(l, r, 42) + mult(l, r, 70) + mult(l, r, 105);
        ans += mult(l, r, 15 * 14);
        cout << ans << '\n';
    }
}