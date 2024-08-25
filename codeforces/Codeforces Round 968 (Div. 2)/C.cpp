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
        int cnt[27] = {};
        for(char c : s) cnt[c - 'a']++;

        set<pair<int, char>> freq;
        for(int i = 0; i < 27; ++i) if(cnt[i]) freq.insert({cnt[i], i + 'a'});

        string ans;
        while(freq.size() > 1){
            pair<int, char> maxi = *freq.rbegin();
            freq.erase(maxi);
            ans += maxi.second;
            maxi.first--;

            pair<int, char> mini = *freq.begin();
            freq.erase(mini);
            ans += mini.second;
            mini.first--;

            if(mini.first) freq.insert(mini);
            if(maxi.first) freq.insert(maxi);
        }

        if(freq.size()) for(int i = 0; i < freq.begin()->first; ++i) ans += freq.begin()->second;

        cout << ans << '\n';
    }
}
