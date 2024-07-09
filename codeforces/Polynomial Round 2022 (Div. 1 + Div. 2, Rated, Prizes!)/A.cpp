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
        int sum = s[0] - '0';
        for(int i = 1; i < n; ++i){
            int d = s[i] - '0';
            if(abs(sum + d) <= abs(sum)) cout << '+', sum += d;
            else cout << '-', sum -= d;
        }
        cout << '\n';
    }
}
