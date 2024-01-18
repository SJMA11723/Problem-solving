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
        int a, b; cin >> a >> b;
        int dif = abs(a - b);
        int64_t cnt = 0;
        while(dif > 0) dif -= ++cnt;
        dif *= -1;
        cout << cnt << '\n';
    }
}
