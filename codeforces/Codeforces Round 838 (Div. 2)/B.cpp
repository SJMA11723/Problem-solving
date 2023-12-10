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
        pair<long long, int> arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr, arr + n);
        vector<pair<int, long long>> ops;
        for(int i = 1; i < n; ++i){
            if(arr[i].first % arr[i - 1].first == 0) continue;
            ops.push_back({arr[i].second, (arr[i].first + arr[i - 1].first - 1) / arr[i - 1].first * arr[i - 1].first - arr[i].first});
            arr[i].first = (arr[i].first + arr[i - 1].first - 1) / arr[i - 1].first * arr[i - 1].first;
        }
        cout << ops.size() << '\n';
        for(auto [i, x] : ops) cout << i << ' ' << x << '\n';
    }
}
