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
        stack<int> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= 4; ++j){
                char c; cin >> c;
                if(c == '#') ans.push(j);
            }
        }

        while(ans.size()){
            cout << ans.top() << " \n"[ans.size() == 1];
            ans.pop();
        }
    }
}
