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
        string a; cin >> a;
        int cub[300] = {};
        for(char c : a) cub[c]++;

        int ans = 0;
        for(char c = 'A'; c <= 'G'; ++c){
            if(cub[c] < m) ans += m - cub[c];
        }
        cout << ans << '\n';
    }
}
