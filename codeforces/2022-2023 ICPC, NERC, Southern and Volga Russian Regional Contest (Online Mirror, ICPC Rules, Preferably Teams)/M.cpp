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
        int raiz = sqrt(n);
        int div = 1;
        for(int i = 2; i <= raiz; ++i){
            if(n % i == 0){
                div = n / i;
                break;
            }
        }
        cout << div << ' ' << n - div << '\n';
    }
}
