/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pref[MAXVAL + 1]; pref[0] = 0;
    for(int i = 1; i <= MAXVAL; ++i){
        pref[i] = 0;
        int tmp = i;
        while(tmp){
            pref[i]++;
            tmp /= 3;
        }
        pref[i] += pref[i - 1];
    }

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        cout << pref[r] + pref[l] - 2 * pref[l - 1] << '\n';
    }
}
