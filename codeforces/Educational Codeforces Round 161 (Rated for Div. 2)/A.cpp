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
        string a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if( (a[i] == b[i] && c[i] != a[i]) || (a[i] != b[i] && c[i] != a[i] && c[i] != b[i]) )
                ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
