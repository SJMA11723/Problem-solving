/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct interval{
    int l, r;
    bool operator<(const interval &b){
        return r < b.r;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    map<int, vector<interval>> cub;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j < n; ++j){
            sum += arr[j];
            cub[sum].push_back({i + 1, j + 1});
        }
    }

    vector<interval> ans;
    for(auto& [sum, intervals] : cub){
        sort(intervals.begin(), intervals.end());
        vector<interval> max_set;
        for(interval &I : intervals)
            if(max_set.empty() || max_set.back().r < I.l) max_set.push_back(I);

        if(ans.size() < max_set.size()) ans = max_set;
    }

    cout << ans.size() << '\n';
    for(interval &I : ans) cout << I.l << ' ' << I.r << '\n';
}
