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
        if(n % 3 == 0) cout << n / 3 << ' ' << n / 3 + 1 << ' ' << n / 3 - 1 << '\n';
        else if(n % 3 == 1) cout << n / 3 << ' ' << n / 3 + 2 << ' ' << n / 3 - 1 << '\n';
        else cout << n / 3 + 1 << ' ' << n / 3 + 2 << ' ' << n / 3 - 1 << '\n';
    }
}
