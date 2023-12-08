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
        if(n % 2){
            cout << "NO\n";
            continue;
        }
        n /= 2;
        int raiz = sqrt(n);
        if(raiz * raiz == n){
            cout << "YES\n";
            continue;
        }

        if(n % 2){
            cout << "NO\n";
            continue;
        }

        n /= 2;
        raiz = sqrt(n);
        if(raiz * raiz == n) cout << "YES\n";
        else cout << "NO\n";
    }
}
