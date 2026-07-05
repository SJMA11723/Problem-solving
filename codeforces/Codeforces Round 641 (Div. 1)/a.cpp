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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n + 1];
    int prefg[n + 2] = {};
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        prefg[i] = gcd(arr[i], prefg[i - 1]);
    }
    int suffg[n + 2] = {};
    for(int i = n; 1 <= i; --i) suffg[i] = gcd(arr[i], suffg[i + 1]);

    ll ans = 1;
    for(int i = 1; i <= n; ++i) ans = lcm(ans, gcd(prefg[i - 1], suffg[i + 1]));
    cout << ans << '\n';
}
