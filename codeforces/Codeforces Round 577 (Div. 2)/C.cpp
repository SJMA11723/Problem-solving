/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int arr[], int k, int median){
    int64_t sum = 0;
    for(int i = n / 2; i < n; ++i) sum += max(0, median - arr[i]);
    return sum <= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    int l = 0, r = 2e9 + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, arr, k, mid)) l = mid + 1;
        else r = mid;
    }

    cout << l - 1 << '\n';
}
