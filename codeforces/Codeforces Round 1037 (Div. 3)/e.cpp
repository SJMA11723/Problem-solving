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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p[n], s[n];
        for(int &x : p) cin >> x;
        for(int &x : s) cin >> x;
        bool ok = p[n - 1] == s[0];
        for(int i = 1; i < n && ok; ++i) ok = ok && (p[i - 1] % p[i] == 0 && gcd(p[i - 1], s[i]) == s[0]);
        for(int i = n - 2; 0 <= i && ok; --i) ok = ok && (s[i + 1] % s[i] == 0);
        cout << (ok ? "YES\n" : "NO\n");
    }
}
