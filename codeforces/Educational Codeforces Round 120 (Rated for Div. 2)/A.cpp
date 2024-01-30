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
        int arr[3];
        for(int i = 0; i < 3; ++i){
            cin >> arr[i];
        }
        sort(arr, arr + 3);
        if((arr[0] == arr[1] && arr[2] % 2 == 0) || (arr[1] == arr[2] && arr[0] % 2 == 0) || (arr[0] + arr[1] == arr[2]) ) cout << "YES\n";
        else cout << "NO\n";
    }
}
