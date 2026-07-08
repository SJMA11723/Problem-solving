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
        int n, a, b; cin >> n >> a >> b;
        int g = gcd(a, b);
        int arr[n];
        for(int &x : arr){
            cin >> x;
            x %= g;
        }
        sort(arr, arr + n);
        int ans = arr[n - 1] - arr[0];
        for(int i = 1; i < n; ++i) ans = min(ans, arr[i - 1] + g - arr[i]);
        cout << ans << '\n';
    }
}
