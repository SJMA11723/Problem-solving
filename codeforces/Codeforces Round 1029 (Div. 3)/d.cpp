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
        int arr[n];
        for(int &x : arr) cin >> x;
        ll sum = 2 * accumulate(arr, arr + n, 0ll);
        if(sum % (1ll * n * (n + 1))){
            cout << "NO\n";
            continue;
        }
        sum /= (1ll * n * (n + 1));
        if((arr[0] - sum) % (n - 1)){
            cout << "NO\n";
            continue;
        }
        ll y = (arr[0] - sum) / (n - 1);
        ll x = sum - y;
        cout << (all_of(arr, arr + n, [&](const int &ai){
            int i = &ai - arr;
            return ai == x * (i + 1) + y * (n - i);}) && x >= 0 && y >= 0 ? "YES\n" : "NO\n");
    }
}