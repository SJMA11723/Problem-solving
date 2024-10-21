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
        set<int> mset;
        for(char c : s) mset.insert(c - 'a');
        vector<int> chars;
        for(int x : mset) chars.push_back(x);

        int pos[26];
        fill(pos, pos + 26, -1);
        for(int i = 0; i < chars.size(); ++i)
            pos[chars[i]] = i;

        for(char &c : s) c = chars[ (int)chars.size() - 1 - pos[c - 'a'] ] + 'a';
        cout << s << '\n';
    }
}
