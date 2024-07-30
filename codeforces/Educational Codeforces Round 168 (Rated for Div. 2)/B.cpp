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
        string grid[2];
        cin >> grid[0] >> grid[1];

        int ans = 0;
        for(int i = 1; i < n - 1; ++i){
            int cnt = 0;
            if(grid[0][i + 1] == '.') cnt++;
            if(grid[0][i - 1] == '.') cnt++;
            if(grid[1][i] == '.') cnt++;

            if(cnt == 3 && grid[1][i + 1] == grid[1][i - 1] && grid[1][i + 1] == 'x') ans++;

            cnt = 0;
            if(grid[1][i + 1] == '.') cnt++;
            if(grid[1][i - 1] == '.') cnt++;
            if(grid[0][i] == '.') cnt++;

            if(cnt == 3 && grid[0][i + 1] == grid[0][i - 1] && grid[0][i + 1] == 'x') ans++;
        }
        cout << ans << '\n';
    }
}
