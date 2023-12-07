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
        int n;
        string str;
        cin >> n >> str;
        int unos = 0, ceros = 0;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(str[i] == '1') unos++;
            else ceros++;
            if(i + 1 < n && str[i] != str[i + 1])
                ok = true;
        }
        if(ok || ceros > unos) cout << "YES\n";
        else cout << "NO\n";
    }
}
