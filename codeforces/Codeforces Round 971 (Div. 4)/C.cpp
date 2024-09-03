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
        int64_t x, y, k; cin >> x >> y >> k;
        int stepsy = (y + k - 1) / k, stepsx = (x + k - 1) / k;
        if(stepsx <= stepsy) cout << stepsy * 2 << '\n';
        else cout << stepsx * 2 - 1 << '\n';
    }
}
