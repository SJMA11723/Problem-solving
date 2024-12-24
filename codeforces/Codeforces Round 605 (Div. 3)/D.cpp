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
    int L[n], R[n], ans = 1;
    L[0] = 1;
    for(int i = 1; i < n; ++i){
        L[i] = 1;
        if(arr[i - 1] < arr[i]) L[i] = L[i - 1] + 1;
        ans = max(ans, L[i]);
    }

    R[n - 1] = 1;
    for(int i = n - 2; 0 <= i; --i){
        R[i] = 1;
        if(arr[i] < arr[i + 1]) R[i] = R[i + 1] + 1;
    }

    for(int i = 1; i + 1 < n; ++i)
        if(arr[i - 1] < arr[i + 1]) ans = max(ans, L[i - 1] + R[i + 1]);
    cout << ans << '\n';
}
