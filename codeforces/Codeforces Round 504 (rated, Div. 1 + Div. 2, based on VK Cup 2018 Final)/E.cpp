/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string ans_l;
    int r = 1, c = 1;
    while(n - r + n - c > n - 1){
        string res;
        if(r < n){
            cout << "? " << r + 1 << ' ' << c << ' ' << n << ' ' << n << endl;
            cin >> res;
            if(res == "YES"){
                ans_l += "D";
                r++;
                continue;
            }
        }

        ans_l += "R";
        c++;
    }

    string ans_r;
    r = n, c = n;
    while(r - 1 + c - 1 > n - 1){
        string res;
        if(c > 1){
            cout << "? 1 1 " << r << ' ' << c - 1 << endl;
            cin >> res;
            if(res == "YES"){
                ans_r += "R";
                c--;
                continue;
            }
        }

        ans_r += "D";
        r--;
    }
    reverse(ans_r.begin(), ans_r.end());
    cout << "! " << ans_l << ans_r << endl;
}
