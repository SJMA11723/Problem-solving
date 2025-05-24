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
        int pow2 = 4, x = -1;
        while(pow2 <= n + 1){
            if(n % (pow2 - 1) == 0){
                x = n / (pow2 - 1);
                break;
            }
            pow2 <<= 1;
        }
        cout << x << '\n';
    }
}
