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
        int a[n][m], b[n][m];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c; cin >> c;
                a[i][j] = c - '0';
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c; cin >> c;
                b[i][j] = c - '0';
            }
        }

        for(int i = 0; i < n - 1; ++i){
            for(int j = 0; j < m - 1; ++j){
                if((a[i][j] + 1) % 3 == b[i][j]){
                    a[i][j] = (a[i][j] + 1) % 3;
                    a[i][j + 1] = (a[i][j + 1] + 2) % 3;
                    a[i + 1][j] = (a[i + 1][j] + 2) % 3;
                    a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
                } else if((a[i][j] + 2) % 3 == b[i][j]){
                    a[i][j] = (a[i][j] + 2) % 3;
                    a[i][j + 1] = (a[i][j + 1] + 1) % 3;
                    a[i + 1][j] = (a[i + 1][j] + 1) % 3;
                    a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3;
                }
            }
        }

        bool ok = true;
        for(int i = 0; i < n; ++i) ok = ok && a[i][m - 1] == b[i][m - 1];
        for(int i = 0; i < m; ++i) ok = ok && a[n - 1][i] == b[n - 1][i];

        cout << (ok ? "YES\n" : "NO\n");
    }
}
