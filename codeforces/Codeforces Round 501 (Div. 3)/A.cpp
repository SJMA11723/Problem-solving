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
    int n, m; cin >> n >> m;
    int cnt[m + 2] = {};
    for(int i = 0; i < n; ++i){
        int l, r; cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }

    vector<int> ans;
    int sum = 0;
    for(int i = 1; i <= m; ++i){
        sum += cnt[i];
        if(!sum) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' '; cout << '\n';
}
