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
    int n, h, w;
    cin >> n >> h >> w;
    while(n--){
        char c; cin >> c;
        if(c == 'Y' || w == 0){
            cout << "Y ";
            h--;
            w++;
        } else cout << "N ";

        cin >> c;
        if(c == 'Y' || h == 0){
            cout << "Y\n";
            w--;
            h++;
        } else cout << "N\n";
    }
}
