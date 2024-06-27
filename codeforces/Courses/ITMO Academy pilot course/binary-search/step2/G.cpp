/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int arr[], const int k, int64_t x){
    int64_t sum = 0;
    for(int i = 0; i < n; ++i) sum += min(x, 1ll*arr[i]);
    return sum >= x * k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n; cin >> k >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    int64_t l = 0, r = 1e11;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(check(n, arr, k, mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}
