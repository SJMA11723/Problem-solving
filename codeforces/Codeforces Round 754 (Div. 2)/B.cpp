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
        int cnt_0 = 0;
        for(char c : s) cnt_0 += c == '0';
        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if((s[i] == '1' && i < cnt_0) || (s[i] == '0' && i >= cnt_0)) ans.push_back(i + 1);

        if(ans.empty()) cout << "0\n";
        else {
            cout << "1\n" << ans.size() << ' ';
            for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
    }
}
