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
    int a, b, x;
    cin >> a >> b >> x;
    if(x % 2){
        if(a <= b){
            for(int i = 0; i < x/2; ++i) cout << "10";
            cout << string(b - x/2, '1') + string(a - x/2, '0');
        } else {
            for(int i = 0; i < x/2; ++i) cout << "01";
            cout << string(a - x/2, '0') + string(b - x/2, '1');
        }
    } else {
        if(a <= b){
            for(int i = 0; i < x/2; ++i) cout << "10";
            cout << string(a - x/2, '0') + string(b - x/2, '1');
        } else {
            for(int i = 0; i < x/2; ++i) cout << "01";
            cout <<  string(b - x/2, '1') + string(a - x/2, '0');
        }
    }
}
