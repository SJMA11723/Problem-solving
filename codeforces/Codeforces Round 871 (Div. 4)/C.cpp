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
        vector<int> zero, one, both;
        for(int i = 0; i < n; ++i){
            int m; cin >> m;
            string s; cin >> s;
            if(s == "01") one.push_back(m);
            else if(s == "10") zero.push_back(m);
            else if(s == "11") both.push_back(m);
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        sort(both.begin(), both.end());

        int a = (zero.empty() ? 1e9 : zero[0]) + (one.empty() ? 1e9 : one[0]);
        int b = both.empty() ? 1e9 : both[0];

        if(min(a, b) > 1e6) cout << "-1\n";
        else cout << min(a, b) << '\n';
    }
}
