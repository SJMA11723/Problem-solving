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
        pair<int, int> arr[4];
        for(int i = 0; i < 4; ++i) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + 4);
        cout << (arr[1].second - arr[0].second) * (arr[3].first - arr[0].first) << '\n';
    }
}
