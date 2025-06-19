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

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        sort(a, a + n);
        sort(b, b + n);

        int ans = 1;
        for(int i = 0; i < n; ++i){
            int pos = upper_bound(a, a + n, b[i]) - a;
            ans = 1ll * ans * max(0, i + 1 - pos) % MOD;
        }
        cout << ans << '\n';
    }
}