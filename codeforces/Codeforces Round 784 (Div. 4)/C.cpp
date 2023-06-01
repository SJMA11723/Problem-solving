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
        bool okPar = true, okImpar = true;
        int antPar, antImpar; cin >> antImpar >> antPar;
        for(int i = 3; i <= n; ++i){
            int x; cin >> x;
            if(i % 2){
                if(antImpar % 2 != x % 2) okImpar = false;
            } else if(antPar % 2 != x % 2) okPar = false;
        }
        if(okPar && okImpar) cout << "yes\n";
        else cout << "no\n";
    }
}
