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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a <= b && b <= d && c <= d && a <= c){
            cout << "YES\n";
            continue;
        }
        int tmp = a;
        a = c;
        c = d;
        d = b;
        b = tmp;
        if(a <= b && b <= d && c <= d && a <= c){
            cout << "YES\n";
            continue;
        }
        tmp = a;
        a = c;
        c = d;
        d = b;
        b = tmp;
        if(a <= b && b <= d && c <= d && a <= c){
            cout << "YES\n";
            continue;
        }
        tmp = a;
        a = c;
        c = d;
        d = b;
        b = tmp;
        if(a <= b && b <= d && c <= d && a <= c){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
