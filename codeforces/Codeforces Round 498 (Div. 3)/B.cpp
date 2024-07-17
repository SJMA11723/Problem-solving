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
    int k, n; cin >> n >> k;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n, greater<pair<int, int>>());

    bool used[n] = {};
    int total_profit = 0;
    for(int i = 0; i < k; ++i){
        total_profit += arr[i].first;
        used[arr[i].second] = true;
        swap(arr[i].first, arr[i].second);
    }
    sort(arr, arr + n);

    cout << total_profit << '\n';
    int cnt = 0, i;
    for(i = 0; !used[i]; ++i) cnt++;

    cnt++; i++;
    for(; i < n; ++i){
        if(used[i]){
            cout << cnt << ' ';
            cnt = 0;
        }
        cnt++;
    }
    cout << cnt << '\n';
}
