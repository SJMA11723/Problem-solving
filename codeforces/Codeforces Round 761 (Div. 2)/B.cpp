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
        for(int i = 3; i < n; ++i){
            if(__gcd(n - i, i - 1) == 1){
                cout << n - i << ' ' << i - 1 << ' ' << 1 << '\n';
                break;
            }
        }
    }
}
