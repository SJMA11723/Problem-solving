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
        int n, m; cin >> n >> m;
        bool reading = true, ans = false;
        string vika = "vika";
        char mat[n][m];

        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        cin >> mat[i][j];

        int cur = 0;
        for(int j = 0; j < m; ++j, reading = 1)
        for(int i = 0; i < n; ++i)
        if(reading && cur < 4 && vika[cur] == mat[i][j]){
            cur++;
            reading = 0;
        }
        cout << (cur < 4 ? "NO\n" : "YES\n");
    }
}
