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
        int lx = -1e5, rx = 1e5;
        int ly = -1e5, ry = 1e5;
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;

            int clx = -1e5, crx = 1e5;
            int cly = -1e5, cry = 1e5;

            bool can;
            cin >> can; /// left
            if(!can) clx = x;

            cin >> can; /// up
            if(!can) cry = y;

            cin >> can; /// right
            if(!can) crx = x;

            cin >> can; /// down
            if(!can) cly = y;

            lx = max(lx, clx);
            rx = min(rx, crx);

            ly = max(ly, cly);
            ry = min(ry, cry);
        }

        if(rx < lx || ry < ly) cout << "0\n";
        else cout << "1 " << lx << ' ' << ly << '\n';
    }
}
