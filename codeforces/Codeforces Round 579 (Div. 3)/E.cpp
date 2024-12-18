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
    for(int &x : arr) cin >> x;
    sort(arr, arr + n);
    if(arr[0] > 1) arr[0]--;
    int last = arr[0], ans = 1;
    for(int i = 1; i < n; ++i){
        if(arr[i] - 1 > last){
            ans++;
            last = arr[i] - 1;
        } else if(last < arr[i]){
            ans++;
            last = arr[i];
        } else if(last < arr[i] + 1){
            ans++;
            last = arr[i] + 1;
        }
    }
    cout << ans << '\n';
}
