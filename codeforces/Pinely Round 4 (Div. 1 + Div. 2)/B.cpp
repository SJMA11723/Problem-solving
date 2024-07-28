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
        int b[n - 1], a[n] = {};
        for(int i = 0; i < n - 1; ++i){
            cin >> b[i];
            a[i] |= b[i];
            a[i + 1] |= b[i];
        }

        bool ok = true;
        for(int i = 0; i < n - 1; ++i){
            if(b[i] != (a[i] & a[i + 1]) ){
                ok = false;
                break;
            }
        }

        if(ok) for(int i = 0; i < n; ++i) cout << a[i] << " \n"[i + 1 == n];
        else cout << "-1\n";
    }
}
