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
        string p, s; cin >> p >> s;
        vector<int> len_p, len_s;
        p += '#';
        s += '#';
        int cnt = 1;
        for(int i = 1; i < p.size(); ++i){
            if(p[i] != p[i - 1]) len_p.push_back(cnt), cnt = 1;
            else cnt++;
        }

        cnt = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != s[i - 1]) len_s.push_back(cnt), cnt = 1;
            else cnt++;
        }

        if(len_p.size() != len_s.size() || p[0] != s[0]){
            cout << "NO\n";
            continue;
        }

        bool ok = true;
        for(int i = 0; i < len_p.size(); ++i) ok = ok && (len_p[i] <= len_s[i] && len_s[i] <= 2 * len_p[i]);
        cout << (ok ? "YES\n" : "NO\n");
    }
}
