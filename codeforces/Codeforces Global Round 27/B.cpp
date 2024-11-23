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
        if(n == 1 || n == 3) cout << "-1\n";
        else if(n % 2){
            for(int i = 0; i < n - 5; ++i) cout << '3';
            cout << "36366\n";
        } else {
            for(int i = 0; i < n - 2; ++i) cout << '3';
            cout << "66\n";
        }
    }
}
