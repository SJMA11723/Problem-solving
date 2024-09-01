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
        int r = sqrt(n);
        string s; cin >> s;
        if(r * r != n){
            cout << "No\n";
            continue;
        }

        bool ok = true;
        for(int i = 0; i < r; ++i) ok &= s[i] == '1' && s[n - i - 1] == '1';
        for(int i = 1; i + 1 < r; ++i){
            ok &= s[i * r] == '1' && s[i * r + r - 1] == '1';
            for(int j = 1; j + 1 < r; ++j) ok &= s[i * r + j] == '0';
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}
