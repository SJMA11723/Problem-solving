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
        int x; cin >> x;
        if(x <= 1399) cout << "Division 4\n";
        else if(x <= 1599) cout << "Division 3\n";
        else if(x <= 1899) cout << "Division 2\n";
        else cout << "Division 1\n";
    }
}