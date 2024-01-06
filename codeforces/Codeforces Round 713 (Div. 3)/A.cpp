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
        pair<int, int> arr[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            arr[i] = {x, i + 1};
        }
        sort(arr, arr + n);
        if(arr[0].first == arr[1].first) cout << arr[n - 1].second << '\n';
        else cout << arr[0].second << '\n';
    }
}
