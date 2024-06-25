/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t compute(int l, int r, int arr[], int x){
    if(l == r) return arr[l] == x;

    int mid = (l + r) >> 1;
    int64_t res = compute(l, mid, arr, x) + compute(mid + 1, r, arr, x);

    map<int64_t, int> cub;
    int64_t sum = 0;
    for(int i = mid; l <= i; --i){
        sum += arr[i];
        cub[sum]++;
    }

    sum = 0;
    for(int i = mid + 1; i <= r; ++i){
        sum += arr[i];
        res += cub[x - sum];
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << compute(0, n - 1, arr, x);
}
