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
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    vi divs[n + 1];
    int ans = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j += i)
            divs[j].pb(i);
    
    for(int i = n; 0 < i; --i){
        if(arr[i - 1] == -1) continue;

        for(int d : divs[i]){
            if(arr[d - 1] == -1) arr[d - 1] = arr[i - 1] % d;
            else if(arr[d - 1] != arr[i - 1] % d){
                ans = i = 0;
                break;
            }
        }
    }

    if(!ans){
        cout << "0\n";
        return 0;
    }

    for(int p = 2; p <= n; ++p){
        if(sz(divs[p]) > 2) continue;
        int pw = 1;
        while(1ll * pw * p <= n){
            pw *= p;
            if(arr[pw - 1] == -1){
                ans = 1ll * ans * p % MOD;
            }
        }
    }

    cout << ans << '\n';
}