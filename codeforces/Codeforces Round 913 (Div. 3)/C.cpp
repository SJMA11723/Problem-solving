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
        int cub[300] = {};
        for(int i = 0; i < n; ++i) cub[str[i]]++;
        priority_queue<pair<int, char>> maxi;
        for(int i = 'a'; i <= 'z'; ++i)
            if(cub[i]) maxi.push({cub[i], i});
        while(maxi.size() > 1){
            auto [cnt, c1] = maxi.top();
            maxi.pop();

            auto [cnt2, c2] = maxi.top();
            maxi.pop();

            cnt--;
            cnt2--;
            if(cnt) maxi.push({cnt, c1});
            if(cnt2) maxi.push({cnt2, c2});
        }
        cout << (maxi.empty() ? 0 : maxi.top().first) << '\n';
    }
}
