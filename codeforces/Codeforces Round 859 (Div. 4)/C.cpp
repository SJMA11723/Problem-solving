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
        string str;
        int n;
        cin >> n >> str;
        vector<int> indices[260];
        for(int i = 0; i < n; ++i) indices[str[i]].push_back(i);
        bool ans = true;
        for(int i = 0; i < 260; ++i){
            for(int j = 1; j < indices[i].size(); ++j){
                if(indices[i][j] % 2 != indices[i][j - 1] % 2) ans = false;
            }
        }
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
}
