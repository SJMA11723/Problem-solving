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
        unordered_map<int, int> cnt;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            cnt[arr[i]]++;
        }

        if(cnt.size() == 1){
            cout << "NO\n";
            continue;
        }

        int mini = INT_MAX, val_min = -1;
        for(auto it : cnt){
            if(it.second < mini){
                mini = it.second;
                val_min = it.first;
            }
        }

        vector<int> mins, others;
        for(int i = 0; i < n; ++i){
            if(arr[i] == val_min) mins.push_back(i + 1);
            else others.push_back(i + 1);
        }

        cout << "YES\n";
        for(int v : others) cout << mins.back() << ' ' << v << '\n';
        mins.pop_back();

        for(int v : others){
            if(mins.empty()) break;
            cout << mins.back() << ' ' << v << '\n';
            mins.pop_back();
        }
    }
}
