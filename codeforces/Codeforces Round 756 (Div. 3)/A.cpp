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
        string n; cin >> n;
        if((n.back() - '0') % 2){
            if((n[0]) % 2){
                bool ok = false;
                for(int i = 1; i < n.size(); ++i) ok = ok || (n[i] - '0') % 2 == 0;
                cout << (ok ? "2\n" : "-1\n");
            } else cout << "1\n";
        } else cout << "0\n";
    }
}
