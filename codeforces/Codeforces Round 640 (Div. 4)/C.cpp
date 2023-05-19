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
        long long n, k; cin >> n >> k;
        long long ini = 1, fin = 2e9 + 1;
        while(ini < fin){
            long long mitad = (ini + fin) / 2;
            if(k <= (mitad - mitad / n)) fin = mitad;
            else ini = mitad + 1;
        }
        cout << ini << '\n';
    }
}
