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
    int n; cin >> n;
    int arr[n];
    int mini = INT_MAX, sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
        mini = min(mini, arr[i]);
    }

    int ans = sum;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= arr[i]; ++j){
            if(arr[i] % j) continue;
            ans = min(ans, sum - arr[i] - mini + arr[i] / j + mini * j);
            ans = min(ans, sum - arr[i] - mini + arr[i] / (arr[i] / j) + mini * (arr[i] / j));
        }
    }
    cout << ans << '\n';
}
