/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int l = 2, r = 999;
        while(l < r){
            int a = l + (r - l) / 3;
            int b = r - (r - l) / 3;
            cout << "? " << a << ' ' <<  b << endl;
            int res; cin >> res;
            if(res == a * b) l = b + 1;
            else if(res == a * (b + 1)){
                l = a + 1;
                r = b;
            } else r = a; ///(a + 1) * (b + 1)
        }
        cout << "! " << l << endl;
    }
}

