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
    int n; cin >> n;
    map<int, bool> mapa;
    bool polo = false, todo = true;
    int a1, b1, a, b;
    cin >> a1 >> b1;
    a = a1; b = b1;

    if(abs(a1) == 180) polo = true;
    for(int i = 1; i < n; ++i){
        int a2, b2;
        cin >> a2 >> b2;

        if(abs(a2) == 180) polo = true;

        if(abs(b2 - b1) < 180){
            for(int j = min(b1, b2); j <= max(b1, b2); ++j) mapa[j] = true;
        } else {
            for(int j = -180; j <= min(b1, b2); ++j) mapa[j] = true;
            for(int j = max(b1, b2); j <= 180; ++j) mapa[j] = true;
        }

        a1 = a2;
        b1 = b2;
    }

    if(abs(b - b1) < 180){
        for(int j = min(b1, b); j <= max(b1, b); ++j) mapa[j] = true;
    } else {
        for(int j = -180; j <= min(b1, b); ++j) mapa[j] = true;
        for(int j = max(b1, b); j <= 180; ++j) mapa[j] = true;
    }

    for(int i = -180; i <= 180; ++i){
        cout << i << ": " << mapa[i] << '\n';
    } cout << '\n';

    if(polo || todo) cout << "yes\n";
    else cout << "no\n";
}
