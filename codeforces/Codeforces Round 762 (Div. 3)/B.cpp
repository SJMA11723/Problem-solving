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
    set<int> mset;
    for(int64_t i = 1; i * i <= 1e9; ++i){
        mset.insert(i * i);
        if(i * i * i <= 1e9) mset.insert(i * i * i);
    }
    vector<int> nums;
    for(int x : mset) nums.push_back(x);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << upper_bound(nums.begin(), nums.end(), n) - nums.begin() << '\n';
    }
}
