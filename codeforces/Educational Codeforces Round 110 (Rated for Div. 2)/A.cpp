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
        for(int i = 0; i < 4; ++i){
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr, arr + 4);
        if( (arr[3].second < 2 && arr[2].second < 2) || (arr[3].second > 1 && arr[2].second > 1) ) cout << "NO\n";
        else cout << "YES\n";
    }
}
