/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 31'622'777

using namespace std;

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;
    bitset<MAXN + 1> no_primo;
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
    vector<int> primes;
    criba(MAXN, primes);

    int64_t n; cin >> n;
    while(n){
        for(int p : primes){
            if(1ll * p * p > n) break;
            int cnt = 0;
            while(n % p == 0){
                cnt++;
                n /= p;
            }
            if(cnt) cout << p << '^' << cnt << " \n"[n == 1];
        }
        if(n > 1) cout << n << "^1\n";
        cin >> n;
    }
}
