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
        map<string, set<int>> cub;
        for(int k = 0; k < 3; ++k)
        for(int i = 0; i < n; ++i){
            string str; cin >> str;
            cub[str].insert(k);
        }
        int ans[3] = {};
        for(int k = 0; k < 3; ++k)
        for(auto &it : cub){
            if(it.second.count(k)){
                if(it.second.size() == 1) ans[k] += 3;
                else if(it.second.size() == 2) ans[k] += 1;
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}
