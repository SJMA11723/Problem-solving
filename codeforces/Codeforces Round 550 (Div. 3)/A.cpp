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
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        sort(s.begin(), s.end());
        set<char> ap;
        char prv = s[0] - 1;
        bool ok = true;
        for(char c : s){
            if(c != prv + 1) ok = false;
            prv = c;
            ap.insert(c);
        }
        ok = ok && ap.size() == s.size();
        cout << (ok ? "Yes\n" : "No\n");
    }
}
