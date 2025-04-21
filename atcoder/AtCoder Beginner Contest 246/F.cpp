/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define set_bit(n, i) n |= 1 << (i)

using namespace std;

const int MOD = 998244353;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l; cin >> n >> l;
    int sets[n] = {};
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        for(char c : s) set_bit(sets[i], c - 'a');
    }

    int lim = 1 << n, ans = 0;
    for(int mask = 1; mask < lim; ++mask){
        int inter = -1;
        for(int i = 0; i < n; ++i){
            if(is_on(mask, i)){
                if(inter == -1) inter = sets[i];
                else inter &= sets[i];
            }
        }

        ans += bin_exp(__builtin_popcount(inter), l) * (__builtin_parity(mask) ? 1 : -1);
        if(ans >= MOD) ans -= MOD;
        else if(ans < 0) ans += MOD;
    }
    cout << ans << '\n';
}
