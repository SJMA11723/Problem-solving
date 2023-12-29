/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c){
    return c == 'a' || c == 'e';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        vector<string> ans;
        int cnt_c = 0;
        for(int i = n - 1; 0 <= i; --i){
            if(is_vowel(str[i])) continue;
            if(i + 1 < n && is_vowel(str[i + 1])){
                ans.push_back(str.substr(i, 2 + cnt_c));
                cnt_c = 0;
            } else cnt_c++;
        }
        for(int i = ans.size() - 1; 0 < i; --i) cout << ans[i] << '.';
        cout << ans[0] << '\n';
    }
}
