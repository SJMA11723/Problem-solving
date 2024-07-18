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
    string s, t; cin >> s >> t;

    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(s[i] == t[i]) continue;
        int idx = -1;
        for(int j = i + 1; j < n; ++j){
            if(s[j] == t[i]){
                idx = j;
                break;
            }
        }

        if(idx == -1){
            cout << "-1";
            return 0;
        }

        while(idx != i){
            swap(s[idx], s[idx - 1]);
            ans.push_back({idx});
            idx--;
        }
    }

    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' '; cout << '\n';
}
