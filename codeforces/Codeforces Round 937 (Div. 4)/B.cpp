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
        for(int i = 0; i < 2 * n; ++i){
            for(int j = 0; j < 2 * n; ++j){
                if((i / 2) % 2){
                    if((j / 2) % 2) cout << '#';
                    else cout << '.';
                } else {
                    if((j / 2) % 2) cout << '.';
                    else cout << '#';
                }
            }
            cout << '\n';
        }
    }
}
