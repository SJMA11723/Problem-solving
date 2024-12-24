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
        int n = s.size();
        int cnt[4] = {};
        for(int i = 0; i < n; ++i){
            if(s[i] == 'U') cnt[0]++;
            else if(s[i] == 'D') cnt[1]++;
            else if(s[i] == 'L') cnt[2]++;
            else cnt[3]++;
        }

        int max_len = 0;
        string route;

        if(cnt[0] && cnt[1]) max_len = 2, route = "UD";
        if(cnt[2] && cnt[3]) max_len = 2, route = "LR";

        if(*min_element(cnt, cnt + 4)){
            int mini1 = min(cnt[0], cnt[1]);
            int mini2 = min(cnt[2], cnt[3]);
            route = "";

            for(int i = 0; i < mini1; ++i) route += 'U';
            for(int i = 0; i < mini2; ++i) route += 'R';
            for(int i = 0; i < mini1; ++i) route += 'D';
            for(int i = 0; i < mini2; ++i) route += 'L';
            max_len = route.size();
        }

        cout << max_len << '\n';
        cout << route << '\n';
    }
}
