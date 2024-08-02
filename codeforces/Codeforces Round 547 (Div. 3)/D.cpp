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
    string l, r; cin >> l >> r;
    vector<int> cub_l[300], cub_r[300];
    for(int i = 0; i < n; ++i){
        cub_l[l[i]].push_back(i + 1);
        cub_r[r[i]].push_back(i + 1);
    }

    vector<pair<int, int>> ans;
    for(char c = 'a'; c <= 'z'; ++c){
        while(cub_l[c].size() && cub_r[c].size()){
            ans.push_back({cub_l[c].back(), cub_r[c].back()});
            cub_l[c].pop_back();
            cub_r[c].pop_back();
        }

        while(cub_l[c].size() && cub_r['?'].size()){
            ans.push_back({cub_l[c].back(), cub_r['?'].back()});
            cub_l[c].pop_back();
            cub_r['?'].pop_back();
        }

        while(cub_r[c].size() && cub_l['?'].size()){
            ans.push_back({cub_l['?'].back(), cub_r[c].back()});
            cub_r[c].pop_back();
            cub_l['?'].pop_back();
        }
    }

    while(cub_l['?'].size() && cub_r['?'].size()){
        ans.push_back({cub_l['?'].back(), cub_r['?'].back()});
        cub_l['?'].pop_back();
        cub_r['?'].pop_back();
    }

    cout << ans.size() << '\n';
    for(auto [i, j] : ans) cout << i << ' ' << j << '\n';
}
