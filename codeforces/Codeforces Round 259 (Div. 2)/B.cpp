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
    reverse(arr, arr + n);
    int ans = n - 1 - (min_element(arr, arr + n) - arr);
    reverse(arr, arr + n);
    while(ans && arr[ans - 1] == arr[ans]) ans--;
    cout << ((!ans || arr[n - 1] <= arr[0]) && is_sorted(arr, arr + ans) && is_sorted(arr + ans, arr + n) ? (n - ans) % n : -1) << '\n';
}
