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

#define MAXN 200000

bool check(int n, int arr[], int m, int d){
    for(int i = d; i < n; ++i)
        if((arr[i] % m) != (arr[i - d] % m)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi divs[MAXN + 1];
    for(int i = 1; i <= MAXN; ++i)
        for(int j = i; j <= MAXN; j += i) divs[j].pb(i);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;
        int ans = 0;
        for(int d : divs[n]){
            int g = 0;
            for(int i = d; i < n; ++i){
                if(!g) g = abs(arr[i] - arr[i - d]);
                else g = gcd(g, abs(arr[i] - arr[i - d]));
            } if(!g) g = n + 1;
            if(g > 1 && check(n, arr, g, d)) ans++;
        }
        cout << ans << '\n';        
    }
}
