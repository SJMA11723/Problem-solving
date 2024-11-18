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
        string s, t; cin >> s >> t;
        int r = 0, b = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] < t[i]) b++;
            else if(s[i] > t[i]) r++;
        if(r == b) cout << "EQUAL\n";
        else if(r < b) cout << "BLUE\n";
        else cout << "RED\n";
    }
}
