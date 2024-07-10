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
    map<string, int> cub;
    string ans;
    for(int i = 1; i < n; ++i){
        string x(1, s[i - 1]);
        x += s[i];
        cub[x]++;
        if(cub[ans] < cub[x]) ans = x;
    }
    cout << ans << '\n';
}
