/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

long long dp[MAXN];
long long lp[MAXN];

void criba(int n){
    vector<int> primos;
    primos.reserve(sqrt(n));
    for(long long i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }
        for(int j = 0; i * (long long)primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i]) break;
        }
    }
}

long long sigma0(int n){
    if(n <= 1) return 1;
    if(!dp[n]){
        long long exp = 0, p = lp[n], n0 = n;
        while(n0 % p == 0){
            exp++;
            n0 /= p;
        }
        dp[n] = (exp + 1) * sigma0(n0);
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba(MAXN - 1);

    int ans = 0;
    int a, b, c; cin >> a >> b >> c;
    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= b; ++j){
            for(int k = 1; k <= c; ++k){
                ans += sigma0(i * j * k);
            }
        }
    }
    cout << ans << '\n';
}
