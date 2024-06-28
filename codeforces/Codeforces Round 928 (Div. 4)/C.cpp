/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t precalc[MAXN + 1];
    precalc[0] = 0;
    for(int i = 1; i <= MAXN; ++i){
        int64_t sum = 0;
        int tmp = i;
        while(tmp){
            sum += tmp % 10;
            tmp /= 10;
        }
        precalc[i] = sum + precalc[i - 1];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << precalc[n] << '\n';
    }
}
