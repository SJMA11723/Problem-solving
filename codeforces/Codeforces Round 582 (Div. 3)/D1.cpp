/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> cnt[MAXVAL + 1];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        int ops = 0;
        while(x){
            cnt[x].push_back(ops);
            ops++;
            x >>= 1;
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i <= MAXVAL; ++i)
    if(cnt[i].size() >= k){
        sort(cnt[i].begin(), cnt[i].end());
        ans = min(ans, accumulate(cnt[i].begin(), cnt[i].begin() + k, 0));
    }
    cout << ans << '\n';
}
