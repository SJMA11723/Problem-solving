/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t compute(int l, int r, int arr[], int n){
    if(l == r) return arr[l] % n == 0;

    int mid = (l + r) >> 1;
    int64_t res = compute(l, mid, arr, n) + compute(mid + 1, r, arr, n);

    map<int, int> cub;
    int64_t sum = 0;
    for(int i = mid; l <= i; --i){
        sum += arr[i];
        cub[(sum % n + n) % n]++;
    }

    sum = 0;
    for(int i = mid + 1; i <= r; ++i){
        sum += arr[i];
        res += cub[(n - ((sum % n + n) % n)) % n];
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << compute(0, n - 1, arr, n) << '\n';
}
