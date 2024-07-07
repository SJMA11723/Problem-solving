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
        string mat[2];
        cin >> mat[0] >> mat[1];

        bool ok = true;
        for(int i = 0; i < n; ++i)
            ok = ok && (mat[0][i] != mat[1][i] || mat[0][i] == '0');

        cout << (ok ? "YES\n" : "NO\n");
    }
}
