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
        if(b < c || d < a){
            cout << "1\n";
            continue;
        }

        if(a <= c && d <= b){
            cout << d - c + (a < c) + (d < b) << '\n';
            continue;
        } else if(c <= a && b <= d){
            cout << b - a + (c < a) + (b < d) << '\n';
            continue;
        }

        int intl = max(a, c), intr = min(b, d);
        cout << intr - intl + 2 << '\n';
    }
}
