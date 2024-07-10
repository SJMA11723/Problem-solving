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
    string from, to;
    cin >> from >> to;
    string ans[max(abs(from[0] - to[0]), abs(from[1] - to[1]))];
    cout << max(abs(from[0] - to[0]), abs(from[1] - to[1])) << '\n';
    int idx = 0;
    while(from[0] != to[0]){
        if(from[0] < to[0]) ans[idx] += "R", from[0]++;
        else ans[idx] += "L", from[0]--;
        idx++;
    }

    idx = 0;
    while(from[1] != to[1]){
        if(from[1] < to[1]) ans[idx] += "U", from[1]++;
        else ans[idx] += "D", from[1]--;
        idx++;
    }

    for(string &s : ans) cout << s << '\n';
}
