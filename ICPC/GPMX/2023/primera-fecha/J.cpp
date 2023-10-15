/**
* Author: Mathgic
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    long long arr[n + 1];
    long long ac[n + 1] = {};
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        ac[i] = arr[i] + ac[i - 1];
        ac[i] %= MOD;
    }

    long long S[n + 1] = {};
    for(int i = 1; i <= n; ++i){
        S[i] = S[i - 1] + arr[i] * ac[i - 1];
        S[i] %= MOD;
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << ( (S[b] - S[a - 1] + MOD) % MOD - (ac[a - 1] * ( (ac[b] - ac[a - 1] + MOD) % MOD) % MOD)  + MOD ) % MOD << '\n';
    }
    return 0;
}
