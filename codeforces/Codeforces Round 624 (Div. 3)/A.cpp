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
        int a, b; cin >> a >> b;
        if(a < b){
            int diff = b - a;
            if(diff % 2) cout << "1\n";
            else cout << "2\n";
        } else if(b < a){
            int diff = a - b;
            if(diff % 2) cout << "2\n";
            else cout << "1\n";
        } else cout << "0\n";
    }
}
