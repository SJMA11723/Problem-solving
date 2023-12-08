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
        long long a, b;
        cin >> a >> b;
        if(b == 1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << a << ' ' << a * (2 * b - 1) << ' ' << 2 * a * b << '\n';
    }
}
