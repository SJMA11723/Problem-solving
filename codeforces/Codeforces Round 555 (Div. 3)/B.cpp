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
    int f[10];
    f[0] = 0;
    for(int i = 1; i <= 9; ++i) cin >> f[i];
    bool first = false;
    for(int i = 0; i < n; ++i){
        int d = s[i] - '0';
        if(d > f[d] && first) break;
        if(d < f[d]){
            first = true;
            s[i] = f[d] + '0';
        }
    }
    cout << s << '\n';
}
