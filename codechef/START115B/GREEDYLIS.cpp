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
        int n, x; cin >> n >> x;
        if(!x){
            for(int i = 0; i < n; ++i) cout << i + 1 << ' ';
            cout << '\n';
            continue;
        }

        if(x + 2 > n){
            cout << "-1\n";
            continue;
        }

        cout << x + 2 << ' ';
        for(int i = 1; i <= x + 1; ++i) cout << i << ' ';
        for(int i = x + 3; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }
}
