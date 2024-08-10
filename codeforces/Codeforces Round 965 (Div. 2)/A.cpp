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
        int x, y, k; cin >> x >> y >> k;
        vector<int> ansx(k, x), ansy(k);

        int cury = 1;
        for(int i = 0; i + 1 < k; i += 2){
            ansy[i] = cury;
            ansy[i + 1] = -cury;
            cury++;
        }

        if(k % 2) ansy.back() = k * y;
        else ansy[k - 2] += k * y;

        for(int i = 0; i < k; ++i) cout << ansx[i] << ' ' << ansy[i] << '\n';
    }
}
