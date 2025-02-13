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
        string s; cin >> s;
        int n = s.size();
        bool ok = false;
        for(int i = 1; i < n; ++i)
            if(s[i] == s[i - 1]) ok = true;
        cout << (ok ? 1 : n) << '\n';
    }
}
