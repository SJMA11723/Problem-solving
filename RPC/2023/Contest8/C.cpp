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
    int a, b; cin >> a >> b;
    if(!a && !b){
        cout << "0\n";
        return 0;
    }

    string ans;
    while(a || b){
        int d1 = a % 10, d2 = b % 10;
        if( (d1 <= 2 && d2 <= 2) || (d1 >= 7 && d2 >= 7) ) ans += "0";
        else ans += "9";
        a /= 10;
        b /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
