/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

#define MAXN 100000

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << 1ll * n * (n - 1) % MOD * fact[n] % MOD << '\n';
    }
}
