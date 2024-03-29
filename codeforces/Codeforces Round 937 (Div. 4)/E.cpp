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
        string str; cin >> str;
        vector<int> div;
        for(int i = 1; i * i <= n; ++i){
            if(n % i) continue;
            div.push_back(i);
            if(i * i != n) div.push_back(n / i);
        }
        sort(div.begin(), div.end());
        set<string> sizes[div.size()];
        int ans = INT_MAX;
        for(int f = 0; f < div.size(); ++f){
            int d = div[f];
            for(int i = 0; i < n && sizes[f].size() < 3; i += d)
                sizes[f].insert(str.substr(i, d));
            if(sizes[f].size() >= 3) continue;

            for(string cmp : sizes[f]){
                int cnt = 0;
                for(int i = 0; i < n && cnt < 2; ++i)
                    if(cmp[i % d] != str[i]) cnt++;
                if(cnt < 2){
                    ans = d;
                    f = div.size();
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}
