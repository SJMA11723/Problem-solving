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
    string n; cin >> n;
    int ans = 0, prod = 1;
    for(int i = 0; i < n.size(); ++i){
        if(n[i] == '0') break;
        int d = n[i] - '0';
        if(d > 1) ans = max(ans, prod * (d - 1) * (int)pow(9, n.size() - 1 - i));
        else if(i == 0) ans = max(ans, (int)pow(9, n.size() - 1));
        prod *= d;
    }
    ans = max(ans, prod);
    cout << ans << '\n';
}
