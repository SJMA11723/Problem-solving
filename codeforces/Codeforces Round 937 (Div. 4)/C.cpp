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
        int hh, mm;
        char c;
        cin >> hh >> c >> mm;
        if(hh < 12){
            if(hh == 0) cout << "12:";
            else cout << setw(2) << setfill('0') << hh << ':';
            cout << setw(2) << setfill('0') << mm << " AM\n";
        } else {
            if(hh == 12) cout << "12:";
            else cout << setw(2) << setfill('0') << hh - 12 << ':';
            cout << setw(2) << setfill('0') << mm << " PM\n";
        }
    }
}
