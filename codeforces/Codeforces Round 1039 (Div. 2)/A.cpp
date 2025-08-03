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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        int ans = n;
        int arr[n];
        for(int &x :arr) cin >> x;
        sort(arr, arr + n, greater<int>());
        ll mult = 1;
        for(int i = 0; i < n; ++i){
            int x = arr[i];
            if(mult * x > c) continue;
            ans--;
            mult *= 2;
        }
        cout << ans << '\n';
    }
}