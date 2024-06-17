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
        int min_e = INT_MAX, min_o = INT_MAX;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2) min_o = min(min_o, x);
            else min_e = min(min_e, x);
        }

        if(min_o == INT_MAX || min_e == INT_MAX || min_o < min_e) cout << "YES\n";
        else cout << "NO\n";
    }
}
