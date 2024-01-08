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
        for(int i = 0; i < n; ++i, cout << '\n')
            for(int j = 0; j < m; ++j)
                cout << (i % 2 ? i / 2 : n / 2 + i / 2) * m + j + 1 << ' ';
    }
}
