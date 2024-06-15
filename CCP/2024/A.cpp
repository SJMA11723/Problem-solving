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
    while(cin >> str){
        int mas = 0, menos = 0, ans = 0;
        for(char c : str){
            if(c == '+'){
                if(menos) menos--;
                mas++;
            } else {
                if(mas) mas--;
                menos++;
            }
            ans = max(ans, mas + menos);
        }

        cout << ans << '\n';
    }
}
