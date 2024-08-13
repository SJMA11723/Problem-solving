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
        int64_t arr[n + 1] = {}; arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        string s; cin >> s;

        vector<int> l, r;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'L') l.push_back(i + 1);
            else r.push_back(i + 1);
        }

        sort(l.begin(), l.end(), greater<int>());
        sort(r.begin(), r.end());

        int64_t ans = 0;
        while(l.size() && r.size() && l.back() < r.back()){
            ans += arr[r.back()] - arr[l.back() - 1];
            r.pop_back();
            l.pop_back();
        }
        cout << ans << '\n';
    }
}
