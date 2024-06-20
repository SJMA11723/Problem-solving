/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

void cribaLineal(int n, vector<int> &lp){
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

    int acc[MAXN + 1][11] = {{}};

    vector<int> lp(MAXN + 1);
    cribaLineal(MAXN, lp);

    for(int i = 0; i <= MAXN; ++i){
        int cnt = 0;
        int tmp = i;
        while(tmp > 1){
            int p = lp[tmp];
            while(tmp % p == 0) tmp /= p;
            cnt++;
        }
        acc[i][cnt] = 1;
    }

    for(int i = 1; i <= MAXN; ++i)
        for(int j = 0; j <= 10; ++j)
            acc[i][j] += acc[i - 1][j];

    int t; cin >> t;
    while(t--){
        int a, b, n;
        cin >> a >> b >> n;
        cout << acc[b][n] - acc[a - 1][n] << '\n';
    }
}
