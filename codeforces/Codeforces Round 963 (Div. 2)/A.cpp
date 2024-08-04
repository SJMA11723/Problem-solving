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
        int a = 0, b = 0, c = 0, d = 0;
        for(char cc : s){
            if(cc == 'A') a = min(a + 1, n);
            else if(cc == 'B') b = min(b + 1, n);
            else if(cc == 'C') c = min(c + 1, n);
            else if(cc == 'D') d = min(d + 1, n);
        }
        cout << a + b + c + d << '\n';
    }
}
