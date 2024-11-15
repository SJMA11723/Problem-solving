/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_1100final(int i, const string &s){
    if(i < 3) return false;
    if(i >= s.size()) return false;
    return s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        set<int> idx_nums;
        int n = s.size();
        for(int i = 3; i < n; ++i){
            if(is_1100final(i, s))
                idx_nums.insert(i);
        }

        int q; cin >> q;
        while(q--){
            int i;
            char c;
            cin >> i >> c;
            i--;
            auto it = idx_nums.lower_bound(i);
            if(it != idx_nums.end() && *it - i <= 3) idx_nums.erase(it);

            s[i] = c;

            for(int j = 0; j < 4; ++j)
                if(is_1100final(i + j, s)) idx_nums.insert(i + j);

            cout << (idx_nums.size() ? "YES\n" : "NO\n");
        }
    }
}
