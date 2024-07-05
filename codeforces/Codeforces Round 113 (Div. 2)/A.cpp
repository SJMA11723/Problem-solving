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
    for(auto &p : arr){
        cin >> p.first >> p.second;
        p.second *= - 1;
    }
    sort(arr, arr + n);
    pair<int, int> target = arr[n - k];
    cout << upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target) << '\n';
}
