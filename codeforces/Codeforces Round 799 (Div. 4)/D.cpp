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
        int hh, mm, p, ans = 0;
        char c;
        cin >> hh >> c >> mm >> p;
        int ih = hh, im = mm;
        do{
            mm += p % 60;
            if(mm > 59){
                mm -= 60;
                hh++;
            }

            hh += p / 60;
            hh %= 24;

            if(hh / 10 == mm % 10 && hh % 10 == mm / 10) ans++;
        }while(hh != ih || mm != im);
        cout << ans << '\n';
    }
}
