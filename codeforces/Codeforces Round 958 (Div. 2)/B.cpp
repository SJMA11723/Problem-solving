
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
        int n; cin >> n;
        int cnt = 0;
        bool zero = false;
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == '1'){
                zero = false;
                cnt++;
            } else {
                if(!zero) cnt--;
                zero = true;
            }
        }
        cout << (cnt > 0 ? "Yes\n" : "No\n");
    }
}
