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
        char ant = str[0];
        bool ok = false;
        for(int i = 1; i < n; ++i){
            if(str[i] != ant) ok = true;
            ant = str[i];
        }

        if(ok){
            for(int i = 0; i < n; ++i){
                for(int j = i + 1; j < n; ++j){
                    if(str[i] != str[j]){
                        swap(str[i], str[j]);
                        i = n;
                        break;
                    }
                }
            }
            cout << "YES\n" << str << '\n';
        } else cout << "NO\n";
    }
}
