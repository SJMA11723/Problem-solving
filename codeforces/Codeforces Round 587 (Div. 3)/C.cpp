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
    int x[6], y[6];
    for(int i = 0; i < 6; ++i) cin >> x[i] >> y[i];

    bool ok = false;
    for(long double i = x[0]; i <= x[1]; i += 0.5){
        bool first = false, second = false;
        int intl = -1;
        int intr = -1;

        if(x[2] <= i && i <= x[3]){
            intl = max(y[0], y[2]);
            intr = min(y[1], y[3]);
            first = true;
        }

        int intl2 = -1;
        int intr2 = -1;

        if(x[4] <= i && i <= x[5]){
            intl2 = max(y[0], y[4]);
            intr2 = min(y[1], y[5]);
            second = true;
        }

        int len = 0;
        if(first) len += max(0, intr - intl);
        if(second) len += max(0, intr2 - intl2);
        if(first && second) len -= max(0, min(intr, intr2) - max(intl, intl2));

        if(len < y[1] - y[0]){
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}
