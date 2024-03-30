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
        bool ap[n + 1] = {};
        int x; cin >> x;
        int mex;
        if(x == 1){
            cout << "0 ";
            mex = 1;
            ap[0] = true;
        } else {
            cout << -x << ' ';
            mex = 0;
            ap[-x] = true;
        }
        for(int i = 1; i < n; ++i){
            cin >> x;
            if(mex - x < 0){
                cout << mex << ' ';
                ap[mex] = true;
                while(ap[mex]) mex++;
            } else {
                while(ap[mex - x] || ap[mex]) mex++;
                cout << mex - x << ' ';
                ap[mex - x] = true;
                while(ap[mex]) mex++;
            }
        }
        cout << '\n';
    }
}
