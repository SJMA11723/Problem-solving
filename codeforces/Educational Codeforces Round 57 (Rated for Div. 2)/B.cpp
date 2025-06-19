#/**
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

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int first[26], last[26];
    fill(first, first + 26, INT_MAX);
    memset(last, -1, sizeof(last));
    for(int i = 0; i < n; ++i){
        int v = s[i] - 'a';
        first[v] = min(first[v], i);
        last[v] = i;
    }

    int ans = 1;
    for(int i = 0; i < 26; ++i){
        if(last[i] == -1) continue;

        int l = INT_MAX, r = -1;
        for(int j = 0; j < 26; ++j){
            if(i == j || last[j] == -1) continue;
            l = min(l, first[j]);
            r = max(r, last[j]);
        }

        if(l || r + 1 < n){
            ans += (1ll * (l + 1) * (n - r) - 1) % MOD;
            if(ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}