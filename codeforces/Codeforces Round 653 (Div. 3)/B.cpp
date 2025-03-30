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
        int n; cin >> n;
        int exp2 = 0, exp3 = 0;
        while(n && n % 2 == 0){
            exp2++;
            n >>= 1;
        }

        while(n && n % 3 == 0){
            exp3++;
            n /= 3;
        }

        if(n > 1 || exp3 < exp2) cout << "-1\n";
        else cout << 2 * exp3 - exp2 << '\n';
    }
}
