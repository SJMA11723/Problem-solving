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

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int k, n; cin >> k >> n;
        vi divs;
        for(int d = 1; d * d <= n; ++d){
            if(n % d) continue;
            divs.pb(d);
            if(d * d != n) divs.pb(n / d);
        }
        sort(all(divs));

        int N = sz(divs);
        int ans[N];
        for(int i = 0; i < N; ++i) ans[i] = bin_exp(k, divs[i]);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(divs[j] % divs[i]) continue;
                ans[j] -= ans[i];
                if(ans[j] < 0) ans[j] += MOD;
            }
        }
        cout << ans[N - 1] << '\n';
    }
}