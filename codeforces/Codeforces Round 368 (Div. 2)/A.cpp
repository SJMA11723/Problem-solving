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
    int n, m; cin >> n >> m;
    char c;
    bool color = false;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        cin >> c;
        if(c == 'M' || c == 'C' || c == 'Y') color = true;
    }
    cout << (color ? "#Color\n" : "#Black&White\n");
}
