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
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1]) continue;
        cnt++;

        set<char> colors;
        colors.insert('R');
        colors.insert('G');
        colors.insert('B');
        colors.erase(s[i - 1]);
        if(i + 1 < n) colors.erase(s[i + 1]);

        s[i] = *colors.begin();
    }
    cout << cnt << '\n' << s << '\n';
}
