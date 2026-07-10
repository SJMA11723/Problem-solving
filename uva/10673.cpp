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

int gcd_ext(int a, int b, ll &x, ll &y){
    if(!b){x = 1; y = 0; return a;}
    ll x1, y1;
    int g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;
        int a = x / k;
        int b = (x + k - 1) / k;
        if(a == b) x = k, a = b = 1;
        ll m, n;
        gcd_ext(a, b, m, n);
        cout << m * x << ' ' << n * x << '\n';
    }
}