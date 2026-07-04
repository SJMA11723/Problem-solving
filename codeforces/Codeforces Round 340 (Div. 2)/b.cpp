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
    int n; cin >> n;
    int cnt = 0;
    ll ans = 1;
    bool prv1 = 0;
    for(int i = 0; i < n; ++i){
        bool x; cin >> x;
        if(x){
            if(prv1) ans *= cnt + 1;
            cnt = 0;
            prv1 = 1;
        } else cnt++;
    } if(!prv1) ans = 0;
    cout << ans << '\n';
}