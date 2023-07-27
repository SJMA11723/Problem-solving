/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<long long> &primos){
    primos.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
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
    int t; cin >> t;
    vector<long long> primos;
    criba(100000, primos);
    for(long long &p : primos) p *= p;
    while(t--){
        long long n, k;
        cin >> n >> k;
        auto posN = lower_bound(primos.begin(), primos.end(), n);
        auto posK = upper_bound(primos.begin(), primos.end(), k);
        cout << posN - primos.begin() << ' ' << max( int(posN - posK), 0) << '\n';
    }
}
