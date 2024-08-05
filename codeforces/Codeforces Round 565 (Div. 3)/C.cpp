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
    int nums[6] = {4, 8, 15, 16, 23, 42};
    set<int> indices[6];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        indices[lower_bound(nums, nums + 6, x) - nums].insert(i);
    }

    while(indices[0].size()){
        vector<int> seq;
        seq.push_back(*indices[0].begin());
        for(int i = 1; i < 6; ++i){
            auto it = indices[i].upper_bound(seq.back());
            if(it == indices[i].end()) break;
            seq.push_back(*it);
        }

        if(seq.size() < 6) break;
        for(int i = 0; i < 6; ++i) indices[i].erase(seq[i]);
    }

    int ans = 0;
    for(int i = 0; i < 6; ++i) ans += indices[i].size();
    cout << ans << '\n';
}
