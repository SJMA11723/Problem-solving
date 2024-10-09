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
    vector<string> nums;
    for(int i = 14; i < 1000; i += 7) nums.push_back(to_string(i));
    int t; cin >> t;
    while(t--){
        string n; cin >> n;
        string ans;
        int mini = 4;
        for(string s : nums){
            if(s.size() != n.size()) continue;

            int cnt = 0;
            for(int i = 0; i < s.size(); ++i) cnt += s[i] != n[i];

            if(cnt < mini){
                mini = cnt;
                ans = s;
            }
        }
        cout << ans << '\n';
    }
}
