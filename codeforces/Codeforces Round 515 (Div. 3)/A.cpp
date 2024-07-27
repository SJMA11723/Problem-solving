/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        if(L < l) cout << L / v << '\n';
        else if(L <= r) cout << (l - 1) / v << '\n';
        else cout << L / v - r / v + (l - 1) / v << '\n';
    }
}
