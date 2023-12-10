/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    int raiz = sqrt(n);
    for(int i = 2; i <= raiz; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        if(r < 4 || (l == r && is_prime(l))) cout << "-1\n";
        else if(l < r) cout << r * (r % 2 == 0) / 2 + (r - 1) * (r % 2) / 2 << ' ' << r * (r % 2 == 0) / 2 + (r - 1) * (r % 2) / 2 << '\n';
        else {
            for(int i = 2; i <= l; ++i){
                if(l % i == 0){
                    cout << i << ' ' << l - i << '\n';
                    break;
                }
            }
        }
    }
}
