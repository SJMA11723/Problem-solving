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
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        if(arr[2] == arr[1]) cout << "YES\n" << arr[0] << ' ' << arr[0] << ' ' << arr[2] << '\n';
        else cout << "NO\n";
    }
}
