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
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];

        sort(arr, arr + n);
        long long suma = 1;
        bool ok = true;
        for(int i = 1; i < n; ++i){
            if(suma < arr[i]){
                ok = false;
                break;
            }
            suma += arr[i];
        }
        if(ok && arr[0] == 1) cout << "yes\n";
        else cout << "no\n";
    }
}
