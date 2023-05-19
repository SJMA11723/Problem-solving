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
        if(n < 4){
            cout << "-1\n";
            continue;
        }
        vector<int> ans;
        for(int i = 1; i <= n; i += 2) ans.push_back(i);
        reverse(ans.begin(), ans.end());
        ans.push_back(4);
        ans.push_back(2);
        for(int i = 6; i <= n; i += 2) ans.push_back(i);
        for(int it : ans) cout << it << ' ';
        cout << '\n';
    }
}
