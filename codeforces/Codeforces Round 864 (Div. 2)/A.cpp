/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dir_i[4] = {-1, 0, 1, 0}, dir_j[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int con1 = 0, con2 = 0;
        for(int i = 0; i < 4; ++i){
            int ni = a + dir_i[i],
                nj = b + dir_j[i];
            if(0 < ni && 0 < nj && ni <= n && nj <= m) con1++;

            ni = c + dir_i[i];
            nj = d + dir_j[i];
            if(0 < ni && 0 < nj && ni <= n && nj <= m) con2++;
        }
        cout << min(con1, con2) << '\n';
    }
}
