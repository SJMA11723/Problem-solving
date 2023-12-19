/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<int> &lp){
    lp.resize(n + 1);
    if(n < 2) return;

    vector<int> primos;

    for(long long i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }

        for(int j = 0; (long long) primos[j] * i <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i]) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> lp;
    criba(1e6, lp);
    int n; cin >> n;
    while(n--){
        long long x; cin >> x;
        long long raiz = sqrt(x);
        if(raiz * raiz == x && lp[raiz] == raiz) cout << "YES\n";
        else cout << "NO\n";
    }
}
