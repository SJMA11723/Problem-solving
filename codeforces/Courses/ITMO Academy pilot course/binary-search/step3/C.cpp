/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int arr[], const int k, const int min_dist){
    int cnt = 0;
    int ant = -1e9 - 10;
    for(int i = 0; i < n; ++i){
        if(min_dist <= arr[i] - ant){
            ant = arr[i];
            cnt++;
        }
    }
    return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    int l = 0, r = INT_MAX;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, arr, k, mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}
