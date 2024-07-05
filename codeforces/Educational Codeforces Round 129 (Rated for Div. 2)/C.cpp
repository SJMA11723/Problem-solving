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
        pair<int, pair<int, int>> arr[n];
        int idx = 0;
        for(auto &p : arr) cin >> p.first;
        for(auto &p : arr){
            cin >> p.second.first;
            p.second.second = idx++;
        }
        sort(arr, arr + n);

        bool sorted = true;
        for(int i = 1; i < n; ++i) sorted = sorted && arr[i - 1].second.first <= arr[i].second.first;

        if(!sorted){
            cout << "-1\n";
            continue;
        }

        int p[n];
        for(int i = 0; i < n; ++i) p[arr[i].second.second] = i;

        vector<pair<int, int>> ans;
        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            int cur = i;
            stack<int> st;
            while(!vis[cur]){
                vis[cur] = true;
                st.push(cur);
                cur = p[cur];
            }

            st.pop();
            while(st.size()){
                ans.push_back({st.top(), p[st.top()]});
                st.pop();
            }
        }

        cout << ans.size() << '\n';
        for(auto [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
    }
}
