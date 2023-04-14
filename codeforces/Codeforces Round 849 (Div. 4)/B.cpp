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
        string str; cin >> str;
        int x = 0, y = 0;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(str[i] == 'L') x--;
            else if(str[i] == 'R') x++;
            else if(str[i] == 'U') y++;
            else y--;

            if(x == 1 && y == 1) ok = true;
        }

        if(ok) cout << "yes\n";
        else cout << "no\n";
    }
}
