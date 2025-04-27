#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c; cin >> r >> c;
    char ans[r][c];
    for(int i = 0; i < r; ++i)
    for(int j = 0; j < c; ++j)
    ans[i][j] = '.';

    bool g = false;
    for(int i = 0; i < r; ++i){
        string s; cin >> s;
        int len = s.size();
        int init = 0;
        if((c - len) & 1){
            if(g){
                init = (c - len + 1) / 2;
            } else {
                init = (c - len) / 2;
            }
            g = !g;
        } else {
            init = (c - len) / 2;
        }

        for(int j = 0; j < len; ++j) ans[i][j + init] = s[j];
    }

    for(int i = 0; i < r; ++i, cout << '\n')
    for(int j = 0; j < c; ++j)
    cout << ans[i][j];
}
