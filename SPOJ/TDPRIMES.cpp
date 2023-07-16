/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;

    bool no_primo[n + 1] = {};
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primos.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primos.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> primos;
    primos.reserve(1e6);
    criba(100'000'000, primos);
    for(int i = 0; i < primos.size(); ++i){
        if(i % 100 == 0) cout << primos[i] << '\n';
    }
}
