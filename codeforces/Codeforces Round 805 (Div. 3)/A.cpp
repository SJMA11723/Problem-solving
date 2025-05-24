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
        int m; cin >> m;
        int64_t pow10 = 1;
        while(pow10 * 10 <= m) pow10 *= 10;
        cout << m - pow10 << '\n';
    }
}
