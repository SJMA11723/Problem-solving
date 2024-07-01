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
        long double dist = sqrt(x * x + y * y);
        if(!x && !y) cout << "0\n";
        else if((int)dist == dist) cout << "1\n";
        else cout << "2\n";
    }
}
