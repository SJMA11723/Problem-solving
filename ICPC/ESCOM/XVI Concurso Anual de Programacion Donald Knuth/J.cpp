#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int pow2 = 1, fact = 1;
    for(int i = 1; i <= n; ++i){
        pow2 += pow2;
        if(pow2 >= MOD) pow2 -= MOD;

        fact = 1ll * i * fact % MOD;
    }
    pow2 = 1ll * pow2 * pow2 % MOD;
    fact = 1ll * fact * fact % MOD;
    cout << 1ll * pow2 * fact % MOD << '\n';
}
