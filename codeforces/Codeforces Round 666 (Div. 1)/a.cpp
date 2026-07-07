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
    int arr[n];
    for(int &x : arr) cin >> x;
    if(n == 1){
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -arr[0] << '\n';
        return 0;
    }
    cout << "1 " << n - 1 << '\n';
    for(int i = 0; i + 1 < n; ++i) cout << 1ll * (n - 1) * arr[i] << " \n"[i + 2 == n];
    cout << "1 " << n << '\n';
    for(int i = 0; i + 1 < n; ++i) cout << -1ll * n * arr[i] << ' ';
    cout << "0\n";
    cout << n << ' ' << n << '\n' << -arr[n - 1] << '\n';
}