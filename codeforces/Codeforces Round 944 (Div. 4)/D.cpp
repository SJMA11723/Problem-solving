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
        string str; cin >> str;
        int n = str.size();
        bool cero_uno = false;
        char ant = str[0];
        int ans = 1;
        for(int i = 1; i < n; ++i){
            if(str[i] == '1'){
                if(ant == '0'){
                    if(cero_uno) ans++;
                    else cero_uno = true;
                }
            } else if(ant == '1') ans++;
            ant = str[i];
        }
        cout << ans << '\n';
    }
}
