/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int arr[], int n, int sum, int k){
    int s = 0;
    for(int i = 0; i < n; ++i){
        s += arr[i];
        if(s == sum / k) s = 0;
    }
    return s == 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
        }

        int ans = INT_MAX;
        for(int i = 1; i * i <= sum; ++i){
            if(sum % i) continue;

            if(check(arr, n, sum, i)) ans = min(ans, n - i);
            if(check(arr, n, sum, sum / i)) ans = min(ans, n - sum / i);
        }
        cout << ans << '\n';
    }
}
