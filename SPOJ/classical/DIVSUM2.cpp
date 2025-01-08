/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;
    bitset<100000001> no_primo;
    no_primo[0] = no_primo[1] = 1;
    for(int64_t i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(int64_t j = i * i; j <= n; j += 2 * i)
            no_primo[j] = 1;
    }

    primos.push_back(2);
    for(int i = 3; i <= n; i += 2)
        if(!no_primo[i]) primos.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> primos;
    criba(100000000, primos);

    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        int64_t ans = 1, tmp = n;
        for(int p : primos){
            if(1ll * p * p > tmp) break;

            int64_t powp = p;
            while(tmp % p == 0){
                tmp /= p;
                powp *= p;
            }
            ans *= (powp - 1) / (p - 1);
        }
        if(tmp > 1) ans *= ((__int128_t)tmp * tmp - 1) / (tmp - 1);
        cout << ans - n << '\n';
    }
}
