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
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int gcd = 0;
        for(int i = 0; i < n / 2; ++i){
            if(arr[i] - arr[n - 1 - i] == 0) continue;
            gcd = __gcd(gcd, abs(arr[i] - arr[n - 1 - i]));
        }
        cout << gcd << '\n';
    }
}
