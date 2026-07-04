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
        ll n; cin >> n;
        int l = 0, r = 1.5e9;
        while(l < r){
            int mid = l + (r - l) / 2;
            ll maxi = 1ll * mid * (mid - 1) / 2;
            if(maxi <= n) l = mid + 1;
            else r = mid;
        } r--;
        cout << r + (n - 1ll * r * (r - 1) / 2) << '\n';
    }
}
