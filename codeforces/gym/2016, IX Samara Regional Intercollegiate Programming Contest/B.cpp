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
    int prv = -1;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(x == i){
            if(prv == -1) prv = x;
            else {
                ans.push_back({prv, x});
                prv = -1;
            }
        }
    }
    if(prv != -1){
        if(prv == 1) ans.push_back({1, 2});
        else ans.push_back({1, prv});
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i].first << ' ' << ans[i].second << " \n"[i + 1 == ans.size()];
}
