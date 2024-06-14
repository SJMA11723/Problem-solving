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
        int ans = INT_MAX;
        int ant; cin >> ant;
        for(int i = 1; i < n; ++i){
            int x; cin >> x;
            ans = min(ans, x - ant);
            ant = x;
        }

        if(ans < 0) cout << "0\n";
        else cout << ans / 2 + 1 << '\n';
    }
}
