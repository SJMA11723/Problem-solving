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
        int a, b, c; cin >> a >> b >> c;
        if(a > b && a > c) cout << "0 ";
        else cout << abs(a - max(b, c)) + 1 << ' ';

        if(b > a && b > c) cout << "0 ";
        else cout << abs(b - max(a, c)) + 1 << ' ';

        if(c > b && c > a) cout << "0\n";
        else cout << abs(c - max(b, a)) + 1 << '\n';
    }
}
