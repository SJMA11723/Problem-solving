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
        string s; cin >> s;
        int ans = INT_MAX;
        for(int k = 1; k < n; ++k){
            vector<int> nums;
            for(int i = 0; i < k - 1; ++i) nums.push_back(s[i] - '0');
            nums.push_back((s[k - 1] - '0') * 10 + s[k] - '0');
            for(int i = k + 1; i < n; ++i) nums.push_back(s[i] - '0');

            if(*min_element(nums.begin(), nums.end()) == 0){
                ans = 0;
                break;
            }

            if(*max_element(nums.begin(), nums.end()) == 1){
                ans = min(ans, 1);
                continue;
            }

            int res = 0;
            for(int x : nums) if(x > 1) res += x;
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}
