/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool esPrimo(int x){
    int r = sqrt(x);
    for(int i = 2; i <= r; ++i)
        if(x % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p; cin >> p;
    vector<int> primos;
    for(int i = 2; i < p;  ++i){
        if(esPrimo(i)) primos.push_back(i);
    }
    primos.push_back(p);
    int n = primos.size();
    long long dp[n] = {};
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n && primos[j] - primos[i] <= 14; ++j){
            dp[j] += dp[i];
        }
    }
    cout << dp[n - 1] << '\n';
}
