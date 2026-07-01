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
        int a[n], b[n], c[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        for(int &x : c) cin >> x;

        int pairing_ab = 0;
        for(int i = 0; i < n; ++i){
            bool ok = 1;
            for(int j = 0; j < n; ++j) if(a[j] >= b[(j + i) % n]){
                ok = 0;
                break;
            }
            if(ok) pairing_ab += n;
        }

        int pairing_bc = 0;
        for(int i = 0; i < n; ++i){
            bool ok = 1;
            for(int j = 0; j < n; ++j) if(b[j] >= c[(j + i) % n]){
                ok = 0;
                break;
            }
            if(ok) pairing_bc += 1;
        }
        cout << 1ll * pairing_ab * pairing_bc << '\n';
    }
}
