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
        int r, b, d; cin >> r >> b >> d;
        if(b < r) swap(r, b);
        if(d + 1 >= (b + r - 1) / r) cout << "YES\n";
        else cout << "NO\n";
    }
}
