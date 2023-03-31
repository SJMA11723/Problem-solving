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
    int ans = 0;
    string str;
    cin >> str;
    int ant = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '1'){
            ans = max(ans, (i - ant) / 2);
            ant = i;
        }
    }

    cout << ans << '\n';
}
