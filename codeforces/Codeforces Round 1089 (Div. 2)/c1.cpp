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
        int a[n], b[n];
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int g1, g2 = g1 = 1;
            if(i > 0) g1 = gcd(a[i - 1], a[i]);
            if(i + 1 < n) g2 = gcd(a[i], a[i + 1]);
            ll l = lcm(g1, g2);
            if(l < a[i] && (!i || gcd(a[i - 1], l) == g1) && (i + 1 == n || gcd(l, a[i + 1]) == g2)){
                a[i] = l;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
