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
        if(a == b) cout << "0 0\n";
        else cout << abs(a - b) << ' ' << min(min(a, b) % abs(a - b), abs(a - b) - min(a, b) % abs(a - b)) << '\n';
    }
}
