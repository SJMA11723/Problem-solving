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
    string s; cin >> s;
    int cub[27] = {};
    for(char c : s) cub[c - 'A']++;
    int cnt_odd = 0;

    string l, r;
    for(int i = 0; i < 27; ++i){
        if(cub[i] % 2) cnt_odd++;
        l += string(cub[i] / 2, char('A' + i));
    }

    if(cnt_odd > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }

    r = l;
    for(int i = 0; i < 27; ++i){
        if(cub[i] % 2){
            l += char('A' + i);
            break;
        }
    }
    reverse(r.begin(), r.end());
    cout << l << r << '\n';
}
