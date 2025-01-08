/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10'000'000

using namespace std;

void criba(int n, vector<int> &lp){
    lp.clear();
    if(n < 2) return;
    lp.resize(n + 1);
    for(int64_t i = 3; i <= n; i += 2){
        if(lp[i]) continue;
        lp[i] = i;
        for(int64_t j = i * i; j <= n; j += 2 * i)
            if(!lp[j]) lp[j] = i;
    }
    for(int i = 2; i <= n; i += 2) lp[i] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> lp;
    criba(MAXN, lp);

    int n;
    while(cin >> n){
        cout << '1';
        while(n > 1){
            cout << " x " << lp[n];
            n /= lp[n];
        }
        cout << '\n';
    }
}
