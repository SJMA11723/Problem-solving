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
        int n, k;
        cin >> n >> k;

        /// Impares
        if((n - k) % 2 == 0 && n - k >= 0){
            cout << "yes\n";
            cout << 1 + n - k << ' ';
            for(int i = 1; i < k; ++i) cout << "1 ";
            cout << '\n';
            continue;
        }
        if((n - 2*k) % 2 == 0 && n - 2*k >= 0){
            cout << "yes\n";
            cout << 2 + n - 2*k << ' ';
            for(int i = 1; i < k; ++i) cout << "2 ";
            cout << '\n';
            continue;
        }
        cout << "no\n";
    }
}
