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
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int rem = n % 4;
        if(rem == 0) cout << n / 4 << '\n';
        else if(n < 6 || n == 7 || n == 11) cout << "-1\n";
        else if(rem == 1 || rem == 3) cout << n / 4 - 1 << '\n';
        else if(rem == 2) cout << n / 4 << '\n';
    }
}
