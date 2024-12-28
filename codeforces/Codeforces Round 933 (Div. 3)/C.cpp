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
        string s; cin >> s;
        int cnt = 0;
        bool erased[n] = {};
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'p'){
                bool bef = false, aft = false;
                if(0 <= i - 2 && s[i - 1] == 'a' && s[i - 2] == 'm') bef = true;
                if(i + 2 < n && s[i + 1] == 'i' && s[i + 2] == 'e') aft = true;
                if(bef && aft) ans++;
                else if(bef) ans++;
                else if(aft) ans++;
            }
        }
        cout << ans << '\n';
    }
}
