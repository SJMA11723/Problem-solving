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
        ll a, b, d; cin >> a >> b >> d;
        if((d & -d) > min(a & -a, b & -b)){
            cout << "-1\n";
            continue;
        }
        int s = a|b;
        ll x = 0;
        int lsb = __builtin_ffs(d) - 1;
        for(int i = 0; i < 30; ++i) if((s & (1 << i)) && !(x & (1 << i))){
            x += (1ll*d) << (i - lsb);
        }
        cout << x << '\n';
    }
}