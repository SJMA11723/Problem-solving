#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k; cin >> k;
    while(k--){
        ll n, x, t;
        cin >> n >> x >> t;
        ll K = max(0ll, n - t / x);
        ll C = min(n, t / x);
        cout << t / x * K + min(n, t / x) * min(n - 1, t / x - 1) / 2 << '\n';
    }
}