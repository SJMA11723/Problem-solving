/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<int> &lp){
    if(n < 2) return;

    vector<int> primos;

    for(long long i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }

        for(int j = 0; i * (long long)primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i])
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> lp(n + 1);
    criba(n, lp);
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        int tmp = i;
        while(tmp % lp[i] == 0) tmp /= lp[i];

        if(tmp == 1) continue;

        int lpT = lp[tmp];
        while(tmp % lpT == 0) tmp /= lpT;

        if(tmp == 1) ans++;
    }
    cout << ans << '\n';
}
