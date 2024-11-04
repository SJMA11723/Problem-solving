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
    int n; cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr, arr + n, greater<pair<int, int>>());
    int cnt = 0;
    for(int i = 0; i < n; ++i) cnt += arr[i].first * i + 1;
    cout << cnt << '\n';
    for(int i = 0; i < n; ++i) cout << arr[i].second << " \n"[i + 1 == n];
}
