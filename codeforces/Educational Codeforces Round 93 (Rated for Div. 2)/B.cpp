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
        string s; cin >> s;
        vector<int> nums;
        int cnt = 0;
        for(char c : s){
            if(c == '0'){
                if(cnt) nums.push_back(cnt);
                cnt = 0;
            } else cnt++;
        }
        if(cnt) nums.push_back(cnt);

        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = (int)nums.size() - 1; 0 <= i; i -= 2) ans += nums[i];
        cout << ans << '\n';
    }
}
