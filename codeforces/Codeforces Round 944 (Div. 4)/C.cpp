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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) swap(a, b);
        if((a <= c && c <= b && (d < a || b < d)) || (a <= d && d <= b && (c < a || b < c)))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
