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
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n / 2; ++i){
            int a = s[i] - '0';
            int b = s[n - 1 - i] - '0';
            int c = (a + b) / 2;
            ans += abs(a - c) + abs(b - c);
        }
        cout << ans << '\n';
    }
}

