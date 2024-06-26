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
        int a, b, c, d;
        cin >> a >> c >> b >> d;
        if(a < c) cout << (d > b ? "YES\n" : "NO\n");
        else cout << (b > d ? "YES\n" : "NO\n");
    }
}
