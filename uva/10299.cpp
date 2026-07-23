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
    int n;
    while(cin >> n){
        if(n == 0) break;
        ll ans = n - (n == 1);
        for(int i = 2; i * i <= n; ++i){
            if(n % i) continue;
            while(n % i == 0) n /= i;
            ans -= ans / i;
        }
        if(n > 1) ans -= ans / n;
        cout << ans << '\n';
    }
}
