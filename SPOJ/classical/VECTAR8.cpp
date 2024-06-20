/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

void criba(int n, vector<int> &primos, vector<bool> &no_primo){
    primos.clear();
    if(n < 2) return;
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }
    for(int i = 4; i <= n; i += 2) no_primo[i] = true;

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
    vector<int> primos; primos.reserve(MAXN);
    vector<bool> no_primo(MAXN + 1);
    criba(MAXN, primos, no_primo);
    int ans[MAXN + 1] = {};
    for(int &p : primos){
        bool ok = true;
        int mod = 10;
        while(p % mod != p){
            if(no_primo[p % mod]) ok = false;
            mod *= 10;
        }

        int tmp = p;
        while(tmp){
            if(tmp % 10 == 0) ok = false;
            tmp /= 10;
        }

        if(ok) ans[p] = 1;
    }

    for(int i = 1; i <= MAXN; ++i) ans[i] += ans[i - 1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
