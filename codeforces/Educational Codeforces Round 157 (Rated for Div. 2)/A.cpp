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
        int x, y, k; cin >> x >> y >> k;
        if(x <= 0 && 0 <= y || y <= 0 && 0 <= x) cout << abs(x - y) << '\n';
        else if(abs(x) <= abs(y)) cout << abs(y) + max(0, abs(x - y) - k) << '\n';
        else cout << abs(x) << '\n';
    }
}
