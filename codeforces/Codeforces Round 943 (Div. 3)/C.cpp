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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n - 1];
        for(int &x : arr) cin >> x;
        cout << arr[0] + 1 << ' ';
        int prv = arr[0] + 1;
        for(int i = 1; i < n; ++i){
            int k = (i + 1 == n ? 1 : (max(0, arr[i] - arr[i - 1]) + 0) / prv + 1);
            cout << arr[i - 1] + k * prv << " \n"[i + 1 == n];
            prv = arr[i - 1] + k * prv;
        }
    }
}
