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
    int q, x; cin >> q >> x;
    int mex = 0;
    int cnt[x] = {};
    while(q--){
        int y; cin >> y;
        cnt[y % x]++;
        while(cnt[mex % x]){
            cnt[mex % x]--;
            mex++;
        }

        cout << mex << '\n';
    }
}
