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
        int x = 0, y, xx, yy;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c; cin >> c;
                if(c == '.') continue;
                if(!x){
                    x = i + 1;
                    y = j + 1;
                }
                xx = i + 1;
                yy = j + 1;
            }
        }
        cout << x + (abs(x - xx) + abs(y - yy)) / 2 << ' ' << y << '\n';
    }
}
