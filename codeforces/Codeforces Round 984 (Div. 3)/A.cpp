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
        bool ok = true;
        int prv; cin >> prv;
        for(int i = 1; i < n; ++i){
            int x; cin >> x;
            if(abs(x - prv) != 5 && abs(x - prv) != 7) ok = false;
            prv = x;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
