/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool siete(int n){
    while(n){
        if(n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    if(!siete(n) && n % 7) cout << "0\n";
    else if(!siete(n) && n % 7 == 0) cout << "1\n";
    else if(siete(n) && n % 7) cout << "2\n";
    else cout << "3\n";
}
