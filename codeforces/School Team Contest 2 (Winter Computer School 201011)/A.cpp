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
    set<pair<string, string>> ans;
    for(int i = 0 ; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        ans.insert({s1, s2});
    }
    cout << ans.size() << '\n';
}
