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
        int x, y; cin >> x >> y;
        if(y % x){
            cout << "0 0\n";
            continue;
        }

        y /= x;

        cout << 1 << ' ' << y << '\n';
    }
}
