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
        int p1, p2, p3; cin >> p1 >> p2 >> p3;

        if((p3 + p1 + p2) % 2) cout << "-1\n";
        else cout << min(p1 + p2, (p1 + p2 + p3) / 2) << '\n';
    }
}
