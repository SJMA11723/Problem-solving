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
        int n, d; cin >> n >> d;
        cout << "1";
        if(d % 3 == 0 || n >= 3) cout << " 3";
        if(d == 5) cout << " 5";

        /// para el 7
        int rem_nfact = (n >= 3 ? 0 : 2); /// n! % 6
        int rem7 = 1;
        if(rem_nfact) rem7 = 100 % 7;
        rem7 = (rem7 + 6) % 7;
        rem7 = rem7 * d * 4 % 7;

        if(!rem7) cout << " 7";
        if(d % 9 == 0 || n >= 6 || (d % 3 == 0 && n >= 3)) cout << " 9";


        cout << '\n';
    }
}
