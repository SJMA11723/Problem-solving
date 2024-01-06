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
        string b; cin >> b;
        bool left = false;
        cout << b[0];
        for(int i = 1; i < b.size(); i += 2) cout << b[i];
        cout << '\n';
    }
}
