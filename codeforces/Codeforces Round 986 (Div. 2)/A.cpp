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
        int n, a, b; cin >> n >> a >> b;
        int x = 0, y = 0;
        string s; cin >> s;

        bool ok = false;
        for(int i = 0; i < 100; ++i){
            for(char c : s){
                if(c == 'N') y++;
                else if(c == 'S') y--;
                else if(c == 'E') x++;
                else x--;

                if(x == a && y == b) ok = true;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
