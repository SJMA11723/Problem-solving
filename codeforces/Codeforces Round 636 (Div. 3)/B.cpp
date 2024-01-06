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
        if(n / 2 % 2) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < n / 2; ++i) cout << 2 * i + 2 << ' ';
            for(int i = 1; i < n / 2; ++i) cout << 2 * i - 1 << ' ';
            cout << n + n / 2 - 1 << '\n';
        }
    }
}
