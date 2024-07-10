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
        string n; cin >> n;
        if(n.size() == 2){
            cout << n[1] << '\n';
            continue;
        }
        char ans = CHAR_MAX;
        for(int i = 0; i < n.size(); ++i) ans = min(ans, n[i]);
        cout << ans << '\n';
    }
}
