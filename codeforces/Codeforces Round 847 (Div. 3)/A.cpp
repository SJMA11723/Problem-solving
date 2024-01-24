/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const string PI = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string n; cin >> n;
        int ans = 0;
        for(int i = 0; i < n.size(); ++i){
            if(PI[i] != n[i]) break;
            ans++;
        }
        cout << ans << '\n';
    }
}
