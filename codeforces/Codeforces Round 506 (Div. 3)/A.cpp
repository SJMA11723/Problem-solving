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
    int n, k; cin >> n >> k;
    string t; cin >> t;
    int max_pref = 0;
    for(int i = n - 2; 0 <= i; --i){
        bool ok = true;
        for(int j = n - i - 1; j < n; ++j) ok = ok && t[j] == t[j - n + i + 1];
        if(ok){
            max_pref = i + 1;
            break;
        }
    }

    cout << t;
    for(int i = 1; i < k; ++i) cout << t.substr(max_pref);
    cout << '\n';
}
