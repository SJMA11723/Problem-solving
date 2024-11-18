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

        bool f = true;
        int pot = 1;
        int a = 0, b = 0;
        while(n){
            int d = n % 10;
            if(f){
                a += d / 2 * pot;
                b += (d - d / 2) * pot;
            } else {
                b += d / 2 * pot;
                a += (d - d / 2) * pot;
            }

            if(d % 2) f = !f;
            pot *= 10;
            n /= 10;
        }
        cout << a << ' ' << b << '\n';
    }
}
