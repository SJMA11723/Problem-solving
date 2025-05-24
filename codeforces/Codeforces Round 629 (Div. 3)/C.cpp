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
        string c; cin >> c;
        string a(n, '0'), b(n, '0');
        bool one = false;
        for(int i = 0; i < n; ++i){
            if(one){
                a[i] = '0';
                b[i] = c[i];
            } else {
                if(c[i] == '2') a[i] = b[i] = '1';
                else if(c[i] == '0') a[i] = b[i] = '0';
                else {
                    one = true;
                    a[i] = '1';
                    b[i] = '0';
                }
            }
        }
        cout << a << '\n' << b << '\n';
    }
}
