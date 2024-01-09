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
        string s; cin >> s;
        char ant = s[0];
        bool ap[26] = {}, ok = true;
        for(int i = 0; i < s.size(); ++i){
            if( ap[s[i] - 'A'] ) ok = false;
            if(s[i] != ant) ap[s[i - 1] - 'A'] = true;
            ant = s[i];
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
