/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

#define MAXN 5000000

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull pref[MAXN + 1];
    iota(pref, pref + MAXN + 1, 0);
    for(int i = 2; i <= MAXN; ++i) if(pref[i] == i)
    for(int j = i; j <= MAXN; j += i) pref[j] -= pref[j] / i;
    pref[1] = 0;
    for(int i = 1; i <= MAXN; ++i) pref[i] = pref[i] * pref[i] + pref[i - 1];

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int a, b; cin >> a >> b;
        cout << "Case " << tt << ": " << pref[b] - pref[a - 1] << '\n';
    }
}