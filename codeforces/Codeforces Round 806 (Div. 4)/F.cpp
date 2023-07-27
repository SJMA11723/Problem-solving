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
        vector<int> idx, nums;
        idx.reserve(n);
        nums.reserve(n);

        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x < i + 1){
                nums.push_back(x);
                idx.push_back(i + 1);
            }
        }

        long long ans = 0;
        n = idx.size();
        for(int i = 0; i < n; ++i){
            int x = nums[i];
            auto pos = lower_bound(idx.begin(), idx.end(), x);
            ans += pos - idx.begin();
        }

        cout << ans << '\n';
    }
}
