/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 1e9 + 7;

int inv(int x);

int bin_exp(int a, int b){
    if(!b) return 1;
    if(b < 0) return inv(bin_exp(a, -b));
    int tmp = bin_exp(a, b / 2);

    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0, a = 0 , c = 0;
    for(char ci : s) r += ci == '?', c += ci == 'c';

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'a') a++;
        else if(s[i] == 'c') c--;
        else if(s[i] == '?'){
            r--;
            ans += 1ll * bin_exp(3, r + l - 2) * (3 * a + l) % MOD * (3 * c + r) % MOD;
            if(ans >= MOD) ans -= MOD;
            l++;
        } else {
            ans += 1ll * bin_exp(3, r + l - 2) * (3 * a + l) % MOD * (3 * c + r) % MOD;
            if(ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}
