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
        bool ok = 0;
        int x, y;
        for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j) if(arr[j] % arr[i] % 2 == 0){
            ok = 1;
            x = arr[i];
            y = arr[j];
            i = n;
            break;
        }
        if(ok) cout << x << ' ' << y << '\n';
        else cout << "-1\n";
    }
}