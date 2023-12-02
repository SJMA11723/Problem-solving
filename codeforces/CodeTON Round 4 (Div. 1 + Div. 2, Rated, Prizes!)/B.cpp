/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool se_puede(int n, vector<int> &ans){
    if(n == 1 && ans.size()) return true;
    if(n % 2 == 0 || ans.size() == 40) return false;

    ans.push_back(1);
    if(se_puede((n + 1) / 2, ans)) return true;
    ans.pop_back();

    ans.push_back(2);
    if(se_puede((n - 1) / 2, ans)) return true;
    ans.pop_back();

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ans;
        if(!se_puede(n, ans)){
            cout << "-1\n";
            continue;
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int op : ans) cout << op << ' ';
        cout << '\n';
    }
}
