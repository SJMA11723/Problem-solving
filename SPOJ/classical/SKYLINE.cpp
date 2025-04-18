/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

const int MOD = 1e6;
int C[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    C[0] = 1;
    for(int i = 1; i <= MAXN; ++i){
        for(int j = 0; j < i; ++j){
            C[i] += 1ll * C[j] * C[i - 1 - j] % MOD;
            if(C[i] >= MOD) C[i] -= MOD;
        }
    }

    int n; cin >> n;
    while(n){
        cout << C[n] << '\n';
        cin >> n;
    }
}
