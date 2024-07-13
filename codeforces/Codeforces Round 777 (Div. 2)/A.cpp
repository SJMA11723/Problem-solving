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
        if(n % 3 == 2){
            cout << '2';
            for(int i = 0; i < n / 3; ++i) cout << "12";
        } else {
            if(n % 3) cout << '1';
            for(int i = 0; i < n / 3; ++i) cout << "21";
        }
        cout << '\n';
    }
}
