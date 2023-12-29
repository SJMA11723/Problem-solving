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
        char ans;
        for(int i = 0; i < 3; ++i){
            bool A, B, C;
            A = B = C = false;
            for(int j = 0; j < 3; ++j){
                char c; cin >> c;
                if(c == 'A') A = true;
                else if(c == 'B') B = true;
                else if(c == 'C') C = true;
            }

            if(!A) ans = 'A';
            else if(!B) ans = 'B';
            else if(!C) ans = 'C';
        }
        cout << ans << '\n';
    }
}
