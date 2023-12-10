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
        int arr[n], mini = INT_MAX;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            mini = min(mini, arr[i]);
        }
        int gcd = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == mini) continue;
            gcd = __gcd(gcd, abs(arr[i] - mini));
        }
        cout << (gcd ? gcd : -1) << '\n';
    }
}
