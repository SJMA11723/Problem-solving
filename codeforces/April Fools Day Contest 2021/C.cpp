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
    bool ok = true;
    for(int i = 2; i < str.size(); ++i){
        if((str[i - 1] + str[i - 2] - 2 * 'A') % 26 != str[i] - 'A')
            ok = false;
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
