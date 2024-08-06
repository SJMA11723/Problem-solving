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
        int ans[n];
        priority_queue<pair<int, int>> pq;
        pq.push({n, 0});
        for(int i = 0; i < n; ++i){
            auto [len, l] = pq.top();
            pq.pop();
            l = -l;

            int idx = l + (len - 1) / 2;
            ans[idx] = i + 1;

            if(l <= idx - 1) pq.push({idx - l, -l});
            if(idx + 1 <= l + len - 1) pq.push({l + len - 1 - idx, -idx - 1});
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
