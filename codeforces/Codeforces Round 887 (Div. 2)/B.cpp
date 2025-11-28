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
        int n, k; cin >> n >> k;
        int fib = 1, prv = 1; k -= 3;
        while(k-- && fib <= n){
            fib += prv;
            prv = fib - prv;
        }
        if(k > 0){
            cout << "0\n";
            continue;
        }

        int ans = 0;
        for(int A = 0; prv * A <= n; ++A)
            if((n - prv * A) % fib == 0 && A * (fib + prv) <= n) ans++;
        cout << ans << '\n';
    }
}