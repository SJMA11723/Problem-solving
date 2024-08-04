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
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    string ans;
    for(int i = 0; i < n; i += 2){
        if(i + 1 == n) cnt++;
        else {
            if(s[i] != s[i + 1]){
                ans += s[i];
                ans += s[i + 1];
            } else {
                cnt++;
                i--;
            }
        }
    }
    cout << cnt << '\n' << ans << '\n';
}
