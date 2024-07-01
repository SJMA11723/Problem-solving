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
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr, arr + n);

    int r = n - 1;
    for(int l = 0; l < n; ++l){
        while(0 < r && arr[l].first + arr[r].first > k) r--;
        if(l != r && arr[l].first + arr[r].first == k){
            cout << arr[l].second << ' ' << arr[r].second << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}
