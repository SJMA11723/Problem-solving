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
    int n, k; cin >> n >> k;
    string str; cin >> str;
    vector<pair<char, int>> arr;
    for(char c : str){
        if(arr.empty() || c - 'a' != arr.back().first)
            arr.push_back({c - 'a', 1});
        else arr.back().second++;
    }

    n = arr.size();

    if(n == 1){
        cout << "-1\n";
        return 0;
    }

    if(arr[0].first == arr.back().first){
        arr[0].second += arr.back().second;
        arr.back() = arr[0];
        for(int i = 1; i + 1 < n; ++i) arr.push_back(arr[i]);
    } else for(int i = 0; i < n; ++i) arr.push_back(arr[i]);

    int last = 0;
    while(last < n && arr[last].second > k) last++;

    if(last == n){
        cout << "-1\n";
        return 0;
    }

    int ans = 0, len = 0, cub[26] = {};
    int ans_l, ans_r;
    for(int i = last; i < arr.size(); ++i){
        cub[arr[i].first] += arr[i].second;
        len += arr[i].second;
        while(len > str.size() || cub[arr[i].first] > k){
            cub[arr[last].first] -= arr[last].second;
            len -= arr[last++].second;
        }
        if(len > ans){
            ans = len;
            ans_l = last;
            ans_r = i;
        }
    }
    cout << ans << '\n';
    for(int i = ans_l; i <= ans_r; ++i)
        while(arr[i].second--) cout << char(arr[i].first + 'a');
    cout << '\n';
}
