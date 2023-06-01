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
        long long ans = 0;
        vector<vector<long long>> cub(300, vector<long long>(300, 0));
        string str[n];
        for(int i = 0; i < n; ++i){
            cin >> str[i];
            string s = str[i];
            cub[s[0]][s[1]]++;
        }

        for(int i = 0; i < n; ++i){
            string s = str[i];
            for(int j = s[1] + 1; j < 300; ++j) ans += cub[ s[0] ][j];
            for(int j = s[0] + 1; j < 300; ++j) ans += cub[j][ s[1] ];
        }

        cout << ans << '\n';
    }
}

