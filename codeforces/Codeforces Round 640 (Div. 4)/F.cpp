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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if(n0){
            cout << string(n0 + 1, '0');
            if(n2){
                cout << string(n2 + 1, '1');
                for(int i = 0; i < n1 - 1; ++i) cout << i % 2;
            } else {
                for(int i = 1; i <= n1; ++i) cout << i % 2;
            }
        } else if(n2){
            cout << string(n2 + 1, '1');
            for(int i = 0; i < n1; ++i) cout << i % 2;
        } else {
            for(int i = 0; i <= n1; ++i) cout << i % 2;
        }
        cout << '\n';
    }
}
