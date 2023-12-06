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
        char f;
        int c;
        cin >> f >> c;
        for(int i = 1; i < c; ++i) cout << f << i << '\n';
        for(int i = c + 1; i < 9; ++i) cout << f << i << '\n';
        for(char i = 'a'; i < f; ++i) cout << i << c << '\n';
        for(char i = f + 1; i <= 'h'; ++i) cout << i << c << '\n';
    }
}
