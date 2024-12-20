/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct range{
    int l, r;
    const bool operator<(const range &b)const{
        return r - l + 1 < b.r - b.l + 1;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<range> ranges;
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == 'p') ranges.push_back({0, i});
            else if(c == 's') ranges.push_back({i, n - 1});
        }
        sort(ranges.begin(), ranges.end());

        n = ranges.size();
        bool ok = true;
        for(int i = 0; i < n && ok; ++i){
            int l = ranges[i].l, r = ranges[i].r;
            for(int j = i + 1; j < n && ok; ++j){
                int l1 = ranges[j].l, r1 = ranges[j].r;
                if(!(l1 <= l && r <= r1)) ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
