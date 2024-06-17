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
        int a, b, c; cin >> a >> b >> c;
        if(3 - b % 3 > c && b % 3){
            cout << "-1\n";
            continue;
        }

        cout << a + b / 3 + (b % 3 + c + 2) / 3 << '\n';
    }
}
