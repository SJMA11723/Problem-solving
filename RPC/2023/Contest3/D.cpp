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
    string str;
    cin >> str;
    int ans = 0;

    bool flip = false;
    for(int i = 1; i < str.size(); ++i){
        if(str[i] == str[i - 1]){
            if(flip) ans++;
            flip = !flip;
        }
    }

    if(flip) ans++;

    cout << ans << '\n';
}
