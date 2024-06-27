/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int arr[], const int k, const int64_t max_sum){
    int64_t sum = 0;
    int cnt = 1;
    for(int i = 0; i < n; ++i){
        if(arr[i] > max_sum) return false;
        if(sum + arr[i] <= max_sum) sum += arr[i];
        else {
            cnt++;
            sum = arr[i];
        }
    }

    return cnt <= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int64_t l = 0, r = 1e15;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(check(n, arr, k, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
