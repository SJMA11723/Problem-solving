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
    int n, k, q; cin >> n >> k >> q;
    int acc[MAXVAL + 2] = {};
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        acc[a]++;
        acc[b + 1]--;
    }

    int pref[MAXVAL + 1], sum = 0; pref[0] = 0;
    for(int i = 1; i <= MAXVAL; ++i){
        sum += acc[i];
        pref[i] = sum >= k;
        pref[i] += pref[i - 1];
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }
}
