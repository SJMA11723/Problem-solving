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
        ll m; cin >> m;
        ll pairs[n + 1] = {};
        ll sum = 0, ans = 0;
        for(int i = n; 1 < i; --i){
            ll mult = n / i;
            pairs[i] = mult * (mult - 1) / 2;
            for(int j = 2 * i; j <= n; j += i) pairs[i] -= pairs[j];

            int k = i - 1;
            ll cnt = min((m - sum) / k, pairs[i] / k);
            sum += cnt * k;
            ans += cnt * (k + 1);
        }
        cout << (sum == m ? ans : -1) << '\n';
    }
}
