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
        int n, x, y;
        cin >> n >> x >> y;
        int dif = y - x, D = INT_MAX;
        int ans = y;
        for(int d = 1; d * d <= dif; ++d){
            if(dif % d) continue;
            if(n - dif / d - 1 >= 0){
                D = min(D, d);
                break;
            }
            if(n - d - 1 >= 0) D = min(D, dif / d);
        }
        for(int i = x; i <= y; i += D, n--) cout << i << ' ';
        for(int i = x - D; 0 < i && n; i -=D, n--) cout << i << ' ';
        for(int i = y + D; n; i += D, n--) cout << i << ' ';
        cout << '\n';

    }
}
