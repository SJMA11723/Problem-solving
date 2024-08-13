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
        int a, b; cin >> a >> b;
        int pref_xor = a % 2 ? ((a - 1) ^ (a / 2 % 2)) : (a / 2 % 2);
        if(!(pref_xor ^ b)) cout << a << '\n';
        else if((pref_xor ^ b) != a) cout << a + 1 << '\n';
        else cout << a + 2 << '\n';
    }
}
