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
    int n, x; cin >> n >> x;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        pair<int, int> &p = arr[i];
        cin >> p.first;
        p.second = i + 1;
    }
    sort(arr, arr + n);

    for(int l = 0; l < n; ++l){
        int r = n - 1;
        for(int m = l + 1; m < n; ++m){
            while(0 < r && arr[l].first + arr[m].first + arr[r].first > x) r--;
            if(l != r && m != r && arr[l].first + arr[m].first + arr[r].first == x){
                cout << arr[l].second << ' ' << arr[m].second << ' ' << arr[r].second << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
