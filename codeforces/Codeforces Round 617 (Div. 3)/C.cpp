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
        string s; cin >> s;
        map<pair<int, int>, int> last;
        int x = 0, y = 0;
        int l = -1, r;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            else if(s[i] == 'L') x--;
            else x++;

            if(!x && !y){
                if(l == -1 || r - l > i){
                    l = 0;
                    r = i;
                }
            }

            if(last.count({x, y})){
                if(l == -1 || r - l > i - last[{x, y}] - 1){
                    l = last[{x, y}] + 1;
                    r = i;
                }
            }
            last[{x, y}] = i;
        }

        if(l == -1) cout << "-1\n";
        else cout << l + 1 << ' ' << r + 1 << '\n';
    }
}
