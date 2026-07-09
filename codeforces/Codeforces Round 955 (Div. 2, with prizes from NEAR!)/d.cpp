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
        int n, m, k; cin >> n >> m >> k;
        int mat[n + 1][m + 1];
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> mat[i][j];
        char type[n + 1][m + 1];
        ll sum = 0;
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> type[i][j];
            if(type[i][j] == '0') sum += mat[i][j];
            else sum -= mat[i][j];
        }
        if(sum == 0){
            cout << "YES\n";
            continue;
        }

        ll accum[n + 1][m + 1]; memset(accum, 0, sizeof(accum));
        for(int j = 1; j <= m; ++j) for(int i = 1; i <= n; ++i)
            accum[i][j] = accum[i - 1][j] + (type[i][j] == '0' ? 1 : -1);
        ll g = 0;
        for(int i = k; i <= n; ++i){
            ll cur_sum = 0;
            for(int j = 1; j <= k; ++j) cur_sum += accum[i][j] - accum[i - k][j];
            g = gcd(g, abs(cur_sum));
            for(int j = k + 1; j <= m; ++j){
                cur_sum += accum[i][j] - accum[i - k][j];
                cur_sum -= accum[i][j - k] - accum[i - k][j - k];
                g = gcd(g, cur_sum);
            }
        }
        //cout << sum << ' ' << g << '\n';
        cout << (g && sum % g == 0 ? "YES\n" : "NO\n");
    }
}
