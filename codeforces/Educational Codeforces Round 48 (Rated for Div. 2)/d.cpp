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
    int n, m; cin >> n >> m;
    int a[n], b[m], xor1 = 0, xor2 = 0;
    for(int &x : a) cin >> x, xor1 ^= x;
    for(int &x : b) cin >> x, xor2 ^= x;
    if(xor1 != xor2){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    int c11 = a[0];
    for(int i = 1; i < m; ++i) c11 ^= b[i];
    cout << c11 << ' ';
    for(int j = 1; j < m; ++j) cout << b[j] << " \n"[j + 1 == m];
    for(int i = 1; i < n; ++i){
        cout << a[i] << ' ';
        for(int j = 1; j < m; ++j) cout << 0 << " \n"[j + 1 == m];
    }
}
