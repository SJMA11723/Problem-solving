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
        if(a % 2){
            cout << "NO\n";
            continue;
        }

        if(b % 2){
            if(a >= 2) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "YES\n";
    }
}
