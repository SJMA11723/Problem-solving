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
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        if(i % 2){
            if((i - 1) / 2 % 2) {cout << '#'; for(int j = 1; j < m; ++j) cout << '.';}
            else {for(int j = 1; j < m; ++j) cout << '.'; cout << '#';}
        } else for(int j = 0; j < m; ++j) cout << '#';
        cout << '\n';
    }
}
