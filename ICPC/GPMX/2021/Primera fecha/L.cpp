/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void imprimir(long long k){
    if(k == 1){
        cout << "2";
        return;
    }

    if(k % 2){
        cout << "(2*";
        imprimir(k - 1);
        cout << ")";
    } else {
        cout << "(";
        imprimir(k / 2);
        cout << ")^2";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        long long k; cin >> k;
        imprimir(k);
        cout << '\n';
    }
}
