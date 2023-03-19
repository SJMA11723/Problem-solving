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
        int n, sumaPar = 0, sumaImpar = 0;
        cin >> n;
        while(n--){
            int x; cin >> x;
            if(x % 2) sumaImpar += x;
            else sumaPar += x;
        }

        if(sumaImpar < sumaPar) cout << "yes\n";
        else cout << "no\n";
    }
}
