/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str;
        cin >> str;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, str[i] - 'a' + 1);
        }
        cout << ans << '\n';
    }
}
