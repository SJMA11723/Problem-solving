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
        if(n < 7 || n == 9) cout << "NO\n";
        else if(n % 3) cout << "YES\n1 2 " << n - 3 << '\n';
        else cout << "YES\n1 4 " << n - 5 << '\n';
    }
}
