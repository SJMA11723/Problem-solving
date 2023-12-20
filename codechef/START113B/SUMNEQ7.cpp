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
        bool ok = false;
        for(int i = 3; i < n; ++i){
            if(arr[i - 1] + arr[i] != arr[0] + arr[1]){
                ok = true;
                break;
            }
        }

        for(int i = 4; i < n; ++i){
            if(arr[i - 2] + arr[i] != arr[0] + arr[1]){
                ok = true;
                break;
            }
        }

        for(int i = 4; i < n; ++i){
            if(arr[i - 1] + arr[i] != arr[0] + arr[2]){
                ok = true;
                break;
            }
        }

        for(int i = 5; i < n; ++i){
            if(arr[i - 2] + arr[i] != arr[0] + arr[2]){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
