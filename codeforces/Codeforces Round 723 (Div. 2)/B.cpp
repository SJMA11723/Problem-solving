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
        int x; cin >> x;
        bool ok = false;
        for(int i = 0; i < 11; ++i){
            if(x - i * 111 >= 0 && (x - i * 111) % 11 == 0){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
