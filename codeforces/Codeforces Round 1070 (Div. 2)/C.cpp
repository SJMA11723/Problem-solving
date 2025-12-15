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
        int n; cin >> n;
        int max_odd = 0, min_even = INT_MAX;
        int cnt_odd = 0, cnt_even = 0;
        vector<ll> even;
        even.pb(0);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x & 1){
                max_odd = max(max_odd, x);
                cnt_odd++;
            } else {
                even.pb(x);
                cnt_even++;
                min_even = min(min_even, x);
            }
        }
        if(cnt_even == 0) min_even = 0;
        sort(even.begin() + 1, even.end(), greater<ll>());
        for(int i = 1; i <= cnt_even; ++i) even[i] += even[i - 1];

        for(int k = 1; k <= n; ++k){
            if(!cnt_odd){
                cout << '0' << " \n"[k == n];
                continue;
            }
            if(k - 1 <= cnt_even){
                cout << max_odd + even[k - 1] << " \n"[k == n];
            } else {
                if((k - 1 - cnt_even) % 2 == 0) cout << max_odd + even.back() << " \n"[k == n];
                else if(k == n) cout << (cnt_odd % 2 ? max_odd + even.back() : 0) << '\n';
                else cout << (cnt_even ? max_odd + even.back() - min_even : 0) << ' ';
                // impar -> impar + 1 = par
                // par -> todos - minimo
            }
        }
    }
}