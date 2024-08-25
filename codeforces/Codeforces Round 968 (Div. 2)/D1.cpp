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
        int64_t n, m; cin >> n >> m;
        vector<pair<int, int>> mexs;
        while(n--){
            int l; cin >> l;
            int64_t mex = 0;
            set<int> ap;
            int arr[l];
            for(int i = 0; i < l; ++i){
                int x; cin >> x;
                ap.insert(x);
                arr[i] = x;
            }

            mexs.push_back({0, 0});
            while(ap.count(mex)) mex++;
            mexs.back().first = mex;
            mex++;
            while(ap.count(mex)) mex++;
            mexs.back().second = mex;
        }

        int64_t maxi = 0;
        for(auto [mex1, mex2] : mexs) maxi = max({maxi, 1ll*mex1, 1ll*mex2});

        if(maxi <= m)cout << maxi * maxi + m * (m + 1) / 2 - maxi * (maxi - 1) / 2 << '\n';
        else cout << maxi * (m + 1) << '\n';
    }
}
