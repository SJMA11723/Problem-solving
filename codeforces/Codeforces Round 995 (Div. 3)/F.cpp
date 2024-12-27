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
        int n, m, q; cin >> n >> m >> q;
        bool split = false, first = false, last = false;
        vector<pair<int, int>> intervals;
        intervals.push_back({m, m});
        if(m == 1) first = true;
        if(m == n) last = true;
        while(q--){
            int a; cin >> a;
            for(pair<int, int> &I : intervals){
                if(I.second < a){
                    I.second = min(n, I.second + 1);
                } else if(I.first > a){
                    I.first = max(1, I.first - 1);
                } else {
                    first = last = true;
                    if(I.first == I.second){
                        I.first = I.second = -1;
                    } else if(I.first == a){

                    }
                }
            }

            for(int i = 0; i < intervals.size(); ++i){
                if(intervals[i].first == -1){
                    intervals.erase(intervals.begin() + i);
                    i--;
                }
            }

            if(intervals.size()) sort(intervals.begin(), intervals.end());

            if(intervals.empty()){
                if(first) intervals.push_back({1, 1});
                if(last) intervals.push_back({n, n});
            } else {
                if(1 < intervals[0].first && first) intervals.insert(intervals.begin(), {1, 1});
                if(intervals.back().second < n && last) intervals.push_back({n, n});
            }

            intervals.push_back({n + 5, n + 5});
            vector<pair<int, int>> new_intervals;
            int l = 0, r = 0;
            for(pair<int, int> &p : intervals){
                if(l){
                    if(r < p.first){
                        new_intervals.push_back({l, r});
                        l = p.first;
                        r = p.second;
                    } else {
                        r = max(r, p.second);
                    }
                } else {
                    l = p.first;
                    r = p.second;
                }
            }

            intervals = new_intervals;
            int ans = 0;
            for(pair<int, int> &p : intervals) ans += p.second - p.first + 1;
            cout << ans << " \n"[!q];
        }
    }
}
