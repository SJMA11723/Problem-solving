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
        string str; cin >> str;
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == 'B'){
                if(cnt < 0){
                    cnt = 1;
                    ans = i;
                } else cnt++;
            } else cnt--;
        }
        if(cnt < 0) ans = -1;
        cout << ans << '\n';
    }
}
