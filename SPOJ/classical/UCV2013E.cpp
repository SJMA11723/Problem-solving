/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 500

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXN + 1], inv_fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 817016;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * inv_fact[i] * i % MOD;

    int n; cin >> n;
    while(n){
        int xi[n], sum = 0;
        for(int &x : xi){
            cin >> x;
            sum -= x;
        }

        for(int &x : xi){
            int y; cin >> y;
            sum += y;
            x = y - x;
        }

        int ans = fact[sum];
        for(int &x : xi) ans = 1ll * ans * inv_fact[x] % MOD;
        cout << ans << '\n';
        cin >> n;
    }
}
